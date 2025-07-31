package main

import (
	"fmt"
	"os"
)

func main() {
	fmt.Print("033c\033[43;30m\nCriando ficheiro main.wasm...\n")

	file, err := os.Create("main.wasm")
	if err != nil {
		fmt.Println("Erro ao criar o ficheiro:", err)
		return
	}
	defer file.Close()

	write := func(data []byte) {
		_, err := file.Write(data)
		if err != nil {
			panic(err)
		}
	}

	// Cabeçalho
	write([]byte{0x00, 'a', 's', 'm'})
	write([]byte{0x01, 0x00, 0x00, 0x00})

	// Seção de tipos
	write([]byte{0x01, 0x07})                   // section id: 1, size: 7
	write([]byte{0x01, 0x60, 0x02, 0x7F, 0x7F}) // 1 func type: (i32, i32)
	write([]byte{0x01, 0x7F})                   // return i32

	// Seção de funções
	write([]byte{0x03, 0x02, 0x01, 0x00}) // section id: 3, size: 2, 1 func, type index 0

	// Seção de exportações
	write([]byte{0x07, 0x07, 0x01, 0x03}) // section id: 7, size: 7, 1 export, name length: 3
	write([]byte("sum"))                 // name = "sum"
	write([]byte{0x00, 0x00})            // export kind = func, index = 0

	// Seção de código
	write([]byte{0x0A, 0x09, 0x01, 0x07, 0x00}) // section id: 10, size: 9, 1 func, size 7, no locals
	write([]byte{0x20, 0x00, 0x20, 0x01, 0x6A, 0x0B}) // get_local 0, get_local 1, i32.add, end

	fmt.Println("Ficheiro main.wasm criado com sucesso!")
}

