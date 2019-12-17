TABLE_ROW = 5
HASHTABLE = [-1 for _ in range(TABLE_ROW)]
HASHTABLE2 = [[-1, -1] for _ in range(TABLE_ROW)]
prev_index = -1


class Customer:
    def __init__(self, num, name, surname):
        self.num = num
        self.name = name
        self.surname = surname

    def __repr__(self):
        return str(self.num)

    def __str__(self):
        return self.__repr__()


def pretty_table(hashtable):
    for i, v in enumerate(hashtable):
        print(f"{i} -> {v}")


def hash(num: int):
    return num % TABLE_ROW


def add_1(num: str, name: str, surname: str):
    customer = Customer(num, name, surname)
    c_hash = hash(customer.num)
    is_append = False
    if HASHTABLE[c_hash] != -1:
        for _ in range(TABLE_ROW):
            if c_hash >= TABLE_ROW:
                c_hash = 0
            if (HASHTABLE[c_hash] == -1):
                HASHTABLE[c_hash] = customer
                is_append = True
                break
            c_hash += 1
    else:
        HASHTABLE[c_hash] = customer
        is_append = True

    if not is_append:
        print(f"{customer} could not be append")
        return False
    return True


def search_1(num: int):
    c_hash = hash(num)
    _try = 0
    for _ in range(TABLE_ROW):
        _try += 1
        if c_hash >= TABLE_ROW:
            c_hash = 0
        print(
            f"{_try}. Deneme {c_hash}. Satır ({HASHTABLE[c_hash]} var) ", flush=True, end="")
        if (isinstance(HASHTABLE[c_hash], Customer) and HASHTABLE[c_hash].num == num):
            print("Bulundu")
            return HASHTABLE[c_hash]
        else:
            print("Bulunamadı")
        c_hash += 1
    return -1


def add_2(num: str, name: str, surname: str):
    global prev_index
    customer = Customer(num, name, surname)
    c_hash = hash(customer.num)
    is_append = False
    if HASHTABLE2[c_hash][0] == -1:
        HASHTABLE2[c_hash][0] = customer
        prev_index = c_hash
        is_append = True
    else:
        for i in range(TABLE_ROW):
            if HASHTABLE2[i][0] == -1:
                HASHTABLE2[i][0] = customer
                HASHTABLE2[prev_index][1] = i
                prev_index = i
                is_append = True
                break
    if (not is_append):
        print("Tablo dolu")
        return False
    return True


def search_2(num: int):
    c_hash = hash(num)
    _try = 0
    while True:
        _try += 1
        print(
            f"{_try}. Deneme {c_hash}. satır ({HASHTABLE2[c_hash][0]} var) ", flush=True, end="")
        if isinstance(HASHTABLE2[c_hash][0], Customer) and HASHTABLE2[c_hash][0].num == num:
            print("Bulundu")
            return HASHTABLE2[c_hash][0]
        else:
            c_hash = HASHTABLE2[c_hash][1]
            print("Bulunamdı")


add_1(10, "Ömer", "Oruc")
add_1(13, "Ali", "Varol")
add_1(23, "Ahmet", "Yıldırım")
add_1(18, "Ahmet", "Yıldırım")
add_1(50, "Ahmet", "Yıldırım")
pretty_table(HASHTABLE)
print(search_1(18))

print("\n\n")

add_2(10, "Ömer", "Faruk")
add_2(13, "Ali", "Varyemez")
add_2(23, "Ahmet", "Yıldırı")
add_2(18, "Mertcan", "Işık")
add_2(88, "Mertcan", "Işık")
add_2(90, "Mertcan", "Işık")

pretty_table(HASHTABLE2)
print(search_2(18))
