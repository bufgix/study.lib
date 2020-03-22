from PyInquirer import prompt, print_json


TABLE_ROW = 5
HASHTABLE = [-1 for _ in range(TABLE_ROW)]
HASHTABLE2 = [[-1, -1] for _ in range(TABLE_ROW)]
prev_index = -1

# Uygulamanın çalışması için
# $ pip install PyInquirer
# Uygulama 1 için yazılan fonksiyonlar
#   - add_1(num: str, name: str, surname: str)
#   - search_1(num: int)

# Uygulama 2 için yazılan fonksiyonlar
#   -add_2(num: str, name: str, surname: str)
#   -search_2(num: int)


class Customer:
    def __init__(self, num, name, surname):
        self.num = num
        self.name = name
        self.surname = surname

    def __repr__(self):
        return f"Customer  {self.num} {self.name} {self.surname}"

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
            f"{_try}. Deneme ({HASHTABLE[c_hash]} var) ", flush=True, end="")
        if (isinstance(HASHTABLE[c_hash], Customer) and HASHTABLE[c_hash].num == num):
            print("Bulundu")
            return HASHTABLE[c_hash]
        else:
            print("Bulunamadı")
        c_hash += 1
    return None


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
    for _ in range(TABLE_ROW):
        _try += 1
        print(
            f"{_try}. Deneme ({HASHTABLE2[c_hash][0]} var) ", flush=True, end="")
        if isinstance(HASHTABLE2[c_hash][0], Customer) and HASHTABLE2[c_hash][0].num == num:
            print("Bulundu")
            return HASHTABLE2[c_hash][0]
        else:
            c_hash = HASHTABLE2[c_hash][1]
            print("Bulunamdı")
    return None




def main():
    global HASHTABLE, HASHTABLE2, TABLE_ROW, prev_index
    TABLE_ROW = int(input("Tablo boyutu > "))
    HASHTABLE = [-1 for _ in range(TABLE_ROW)]
    HASHTABLE2 = [[-1, -1] for _ in range(TABLE_ROW)]
    prev_index = -1
    
    command_sets = {
        "uygulama 1": {
            "ekle": add_1,
            "ara": search_1,
            "table": HASHTABLE
        },
        "uygulama 2": {
            "ekle": add_2,
            "ara": search_2,
            "table": HASHTABLE2
        }
    }

    try:
        app = prompt({
            "type": "rawlist",
            "name": "app",
            "choices": ["Uygulama 1", "Uygulama 2"],
            "message": "Hangi uygulama",
            "filter": lambda x: x.lower()
        })
        functions = command_sets[app["app"]]
        while True:
            answers = prompt({
                "type": "rawlist",
                "name": "choice",
                "choices": ["Ekle", "Ara"],
                "message": "Hangi işlemi yapmak istiyosun?",
                "filter": lambda x: x.lower()
            })
            if (answers["choice"] == "ekle"):
                params = prompt([
                    {
                        "type": "input",
                        "name": "num",
                        "message": "Numara girin",
                        "validate": lambda x: x.isnumeric() or "Sadece sayi girin",
                        "filter": lambda x: int(x)
                    },
                    {
                        "type": "input",
                        "name": "name",
                        "message": "İsim girin",
                    },
                    {
                        "type": "input",
                        "name": "surname",
                        "message": "Soyisim girin",
                    }
                ])
                functions["ekle"](
                    params["num"], params["name"], params["surname"])
                pretty_table(functions["table"])
            else:
                params = prompt({
                    "type": "input",
                    "name": "num",
                    "message": "Numara girin",
                    "validate": lambda x: x.isnumeric() or "Sadece sayi girin",
                    "filter": lambda x: int(x)
                })
                res = functions["ara"](params["num"])
                if (res):
                    print(res)
                else:
                    print("Bulunamadı")
    except KeyError:
        pass


if __name__ == '__main__':
    main()
