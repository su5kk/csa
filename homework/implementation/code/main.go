package main

import (
	"fmt"
	"os"
	"strconv"
	"sync"
	"time"
)

type Cipher struct {
	table map[rune]int
}

func New() *Cipher {
	cipher := &Cipher{
		table: make(map[rune]int),
	}
	for i := 0; i < 26; i++ {
		cipher.table[rune(i+97)] = i
	}
	return cipher
}

func (c *Cipher) Encrypt(msg string, out chan string, wg *sync.WaitGroup) {
	defer wg.Done()
	encryptedMessage := ""
	for _, v := range msg {
		char := strconv.Itoa(c.table[v])
		encryptedMessage += char
	}
	out <- encryptedMessage
}

func main() {
	start := time.Now()
	cipher := New()
	strings := os.Args[1:]
	receiver := make(chan string)
	wg := sync.WaitGroup{}
	for _, str := range strings {
		wg.Add(1)
		go cipher.Encrypt(str, receiver, &wg)
	}
	go func() {
		wg.Wait()
		close(receiver)
	}()
	for ans := range receiver {
		fmt.Println(ans)
	}
	fmt.Println(time.Since(start).String())
}
