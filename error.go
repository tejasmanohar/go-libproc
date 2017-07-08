package libproc

import (
	"errors"
)

// ErrNotImplemented is a constant for NOT_IMPLEMENTED_ERROR in golibproc.c.
// It is returned by bindings when the underlying libproc method is not available
// on the system. This is achieved through dlopen/dlsym (runtime dispatch).
var ErrNotImplemented = errors.New("not implemented")

func getErr(err error) error {
	if err == nil {
		return nil
	}

	if err.Error() == "errno -1" {
		return ErrNotImplemented
	}

	return err
}
