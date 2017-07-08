package libproc

// #include <libproc.h>
// #include <golibproc.h>
import "C"
import "unsafe"

// RawProcListPIDs is a low-level binding for proc_listpids.
func RawProcListPIDs(_type uint32, typeInfo uint32, buffer unsafe.Pointer, bufferSize int) (int, error) {
	n, err := C.listpids((C.uint32_t)(_type), (C.uint32_t)(typeInfo), buffer, C.int(bufferSize))
	return int(n), getErr(err)
}
