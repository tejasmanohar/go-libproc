package libproc

import (
	"fmt"
	"testing"
)

func TestListPIDs(t *testing.T) {
	fmt.Println(ListPids(1, 0, 0))
}

func TestListAllPIDs(t *testing.T) {
	fmt.Println(ListAllPids(0))
}
