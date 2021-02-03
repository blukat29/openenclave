package main

// #cgo pkg-config: oehost-gcc
// #include "host.h"
import "C"
import (
	"fmt"
	"os"
)

func main() {
	path := C.CString(os.Args[1])
	fmt.Println("--- enclave start")
	C.run_enclave(path)
	fmt.Println("--- enclave end")
}
