package libproc

import (
	"unsafe"
)

// ProcListPidsMaxSize is the max number of Pids on OS X.
// `#define	Pid_MAX		99999`
// https://opensource.apple.com/source/xnu/xnu-1699.24.23/bsd/sys/proc_internal.h
const ProcListPidsMaxSize = 99999

// ListPids is an idiomatic binding to proc_listpids.
func ListPids(_type uint32, typeInfo uint32, bufferSize int) ([]Pid, error) {
	if bufferSize == 0 {
		bufferSize = ProcListPidsMaxSize
	}

	buffer := make([]Pid, bufferSize)
	_, err := RawProcListPids(_type, typeInfo, unsafe.Pointer(&buffer[0]), bufferSize)
	if err != nil {
		return nil, err
	}

	ret := make([]Pid, 0, bufferSize)
	for _, pid := range buffer {
		if pid != 0 {
			ret = append(ret, pid)
		}
	}

	return ret, nil
}

// ListAllPids is an idiomatic binding to proc_listpids.
func ListAllPids(bufferSize int) ([]Pid, error) {
	if bufferSize == 0 {
		bufferSize = ProcListPidsMaxSize
	}

	buffer := make([]Pid, bufferSize)
	_, err := RawProcListAllPids(unsafe.Pointer(&buffer[0]), bufferSize)
	if err != nil {
		return nil, err
	}

	ret := make([]Pid, 0, bufferSize)
	for _, pid := range buffer {
		if pid != 0 {
			ret = append(ret, pid)
		}
	}

	return ret, nil
}
