package libproc

import (
	"errors"
)

// ErrFunctionUnavailable is a constant for FUNCTION_UNAVAILABLE_ERROR in golibproc.c.
// It is returned by bindings when the underlying libproc method is not available
// on the system. This is achieved through dlopen/dlsym (runtime dispatch).
var ErrFunctionUnavailable = errors.New("function unavailable")

func getErr(err error) error {
	if err == nil {
		return nil
	}

	if err.Error() == "errno -1" {
		return ErrFunctionUnavailable
	}

	return err
}
