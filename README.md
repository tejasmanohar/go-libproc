this is a work-in-progress...

# go-libproc

Golang bindings to macOS / OS X `libproc`

## What's libproc?

`libproc` is a macOS (Darwin) shared library that exposes internal kernel data
about running processes. It's the Mac-equivalent of Linux's [procps]
and powers many utilities like `ps` and `lsof`.
