package libproc

import (
	"unsafe"

	low "github.com/tejasmanohar/go-libproc/low"
)

// ProcListPIDsMaxSize is the max number of PIDs on OS X.
// `#define	PID_MAX		99999`
// https://opensource.apple.com/source/xnu/xnu-1699.24.23/bsd/sys/proc_internal.h
const ProcListPIDsMaxSize = 99999

// PID is a process ID.
type PID uint32

func ListPIDs(_type uint32, typeInfo uint32, bufferSize int) ([]PID, error) {
	if bufferSize == 0 {
		bufferSize = ProcListPIDsMaxSize
	}

	buffer := make([]PID, bufferSize)
	_, err := low.ProcListPIDs(_type, typeInfo, unsafe.Pointer(&buffer[0]), bufferSize)
	if err != nil {
		return nil, getErr(err)
	}

	ret := make([]PID, 0, bufferSize)
	for _, pid := range buffer {
		if pid != 0 {
			ret = append(ret, pid)
		}
	}

	return ret, nil
}
