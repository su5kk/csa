from typing import List

from ciphers.ciphers_implementation.base import BaseCipher


class ShiftCipher(BaseCipher):
    def __init__(self):
        super().__init__()

    def __repr__(self):
        return f"It is a shift cipher: message = {self.message}, " \
               f"Div = {self.div:.3f}"

    def fill_randomly(self):
        super().fill_randomly()