"""refactored"""
import random
from string import hexdigits
from typing import Optional

MAX_MESSAGE_LENGTH = 100

def random_string(length: int = MAX_MESSAGE_LENGTH):
    """Случайная строка заданной длины"""
    result_str = ''.join(random.choice(hexdigits) for _ in range(length))
    return result_str


class BaseCipher:
    """Базовый класс шифров"""
    def __init__(self):
        self._message: Optional[str] = None

    @property
    def div(self) -> float:
        """среднее арифметическое строки"""
        return sum(bytearray(self._message, encoding='ascii')) / len(self._message)

    @property
    def message(self):
        return self._message

    @message.setter
    def message(self, value):
        if value:
            self._message = value
        else:
            raise ValueError(f"message excepted to be non-empty string, but input empty")

    def fill_randomly(self):
        self.message = random_string()
