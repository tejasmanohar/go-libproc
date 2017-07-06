package libproc

import "errors"

var NotImplementedError = errors.New("not implemented")

func getErr(err error) error {
	if err == nil {
		return nil
	}

	if err.Error() == "not implemented" {
		return NotImplementedError
	}

	return err
}
