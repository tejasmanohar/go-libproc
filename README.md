# go-libproc

Golang bindings for macOS / OS X `libproc`


## Status

go-libproc has raw bindings for the complete C API as of macOS 10.12.
That said, it could use many more high-level functions.


## FAQ

### What's libproc?

`libproc` is a macOS (Darwin) shared library that exposes internal kernel data
about running processes. It's the Mac-equivalent of Linux's [procps]
and powers many utilities like `ps` and `lsof`.

### How does it work?

go-libproc uses [Cgo](https://golang.org/cmd/cgo/) to call an intermediate C wrapper
that calls `libproc`. While Cgo can be used to call `libproc` directly from Go,
later versions of OS X contain additional functions so the C wrapper uses [`dlopen`](http://man7.org/linux/man-pages/man3/dlopen.3.html)
and ['dlsym'](http://man7.org/linux/man-pages/man3/dlsym.3.html) to load `libproc.dylib`
dynamic shared library at runtime. This allows go-libproc to return
`ErrFunctionUnavailable` from unavailable functions rather than failing to compile on
systems missing some function implementations.

### What methods should I use?

Methods prefixed with `RawProc` (e.g. `RawProcListPIDs`) defined in `bindings.go`
are low-level wrappers of the C API and are very unlikely to change.
However, they're inadvisable for normal usage. I recommend using the
higher-level wrappers built on top of these in `libproc.go` (e.g. `ListPIDs`).

If you find yourself reaching for the low-level bindings and
[`unsafe`](https://golang.org/pkg/unsafe/) code, please open an issue,
or better (assuming you want it done!), a pull request for a new high-level function.
