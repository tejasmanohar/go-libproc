package libproc

import (
	"fmt"
	"testing"
)

func TestListPIDs(t *testing.T) {
	fmt.Println(ListPIDs(1, 0, 0))
}
