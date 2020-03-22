import unittest
import main

class TestHash(unittest.TestCase):
    def test_hash(self):
        self.assertEqual(main.hash(16), 1)
        self.assertEqual(main.hash(5), 0)
        self.assertEqual(main.hash(20), 0)

if __name__ == '__main__':
    unittest.main()
    