package main

import (
	"fmt"
)

const (
	max int = 100
)

func main() {
	hashTable := []int{}
	StringTable := []string{}
	Str1 := "aab"
	Str2 := "abb"
	str := "ab"
	StringTable = append(hashTable, Str1, Str2)
	hashTable ZZ
	fmt.Println(hashTable, str)
	fmt.Println(hasgFunc(Str1))

}

func hasgFunc(S string) int {
	l := len(S)
	id := 0
	for i := 0; i < l; i++ {
		id = id*26 + int(S[i]-'A')
	}
	return id
}
