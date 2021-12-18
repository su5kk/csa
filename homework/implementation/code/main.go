package main

import (
	"fmt"
	"os"
	"strconv"
	"sync"
	"time"
)

type Encryptor interface {
	Encrypt(msg string, out chan string, wg *sync.WaitGroup)
}

type SimpleCipher struct {
	table map[rune]int
}

func New() *SimpleCipher {
	cipher := &SimpleCipher{
		table: make(map[rune]int),
	}
	for i := 0; i < 26; i++ {
		cipher.table[rune(i+97)] = i
	}
	return cipher
}

func (c *SimpleCipher) Encrypt(msg string, out chan string, wg *sync.WaitGroup) {
	defer wg.Done()
	encryptedMessage := ""
	for _, v := range msg {
		char := strconv.Itoa(c.table[v])
		encryptedMessage += char
	}
	out <- encryptedMessage
}

func run(wg *sync.WaitGroup, messages []string, receiver chan string, cipher Encryptor) {
	for _, str := range messages {
		wg.Add(1)
		go cipher.Encrypt(str, receiver, wg)
	}
	go func() {
		wg.Wait()
		close(receiver)
	}()
	for ans := range receiver {
		fmt.Println(ans)
	}
}

func main() {
	start := time.Now()
	cipher := New()
	strings := os.Args[1:]
	receiver := make(chan string)
	wg := sync.WaitGroup{}
	run(&wg, strings, receiver, cipher)
	fmt.Println(time.Since(start).String())
}
