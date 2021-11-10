import random
import time
from abc import ABC
from collections import Sequence
from pathlib import Path
from typing import Optional, Union, List

from ciphers.ciphers_implementation.shift import ShiftCipher
from ciphers.ciphers_implementation.nums import NumsCipher
from ciphers.ciphers_implementation.symbol import SymbolCipher
from ciphers.ciphers_implementation.types import CipherType


"""Класс контейнера шифра"""
class Container(Sequence, ABC):
    def __init__(self, filename: Optional[str] = None, n_random: Optional[int] = None):
        self.ciphers: List[Union[ShiftCipher, SymbolCipher, NumsCipher]] = []
        if filename:
            for line in Path(filename).read_text().splitlines():
                cipher = self.cipher_from_line(line)
                self.ciphers.append(cipher)
        elif n_random:
            if type(n_random) == str:
                n_random = int(n_random)
            for _ in range(n_random):
                cipher = self.random_cipher()
                self.ciphers.append(cipher)
        self.start_time = time.time()

    def __len__(self):
        return len(self.ciphers)

    def __getitem__(self, item):
        return self.ciphers[item]

    """Генерация случайного шифра"""
    @staticmethod
    def random_cipher() -> Union[ShiftCipher, SymbolCipher, NumsCipher]:
        lang_type = random.choice([item.value for item in CipherType])
        cipher = None
        if CipherType(lang_type) == CipherType.SHIFT:
            cipher = ShiftCipher()
        elif CipherType(lang_type) == CipherType.SYMBOL:
            cipher = SymbolCipher()
        elif CipherType(lang_type) == CipherType.NUMS:
            cipher = NumsCipher()
        cipher.fill_randomly()
        return cipher

    """Ввод шифра из строки с его описанием"""
    @staticmethod
    def cipher_from_line(line: str) -> Union[ShiftCipher, SymbolCipher, NumsCipher]:
        
        tokens = line.split()
        if len(tokens) < 2:
            raise Exception("Base cipher must contain at least 2 tokens: "
                                       "type and message")
        cipher_type = tokens[0]
        cipher = None
        if CipherType(cipher_type) == CipherType.SHIFT:
            cipher = ShiftCipher()
        elif CipherType(cipher_type) == CipherType.SYMBOL:
            cipher = SymbolCipher()
        elif CipherType(cipher_type) == CipherType.NUMS:
            cipher = NumsCipher()
        cipher.message = tokens[1]
        return cipher

    """Сортирует контейнер"""
    def sort(self):
        n = len(self.ciphers)
        gap = n // 2
        while gap > 0:
            i = gap
            while i < n:
                temp = self.ciphers[i]

                j = i
                while j >= gap and self.ciphers[j - gap].div > temp.div:
                    self.ciphers[j] = self.ciphers[j - gap]
                    j -= gap
                self.ciphers[j] = temp
                i += 1
            gap //= 2
        
