# 📋 PROJECT PROGRESS — OOP ORDERING APPLICATION

---

# 📅 06/09 — PRODUCT + CUSTOMER

## 📦 TASK 1 — BOOK PRODUCT

**Member:** Minh Tiến

### 📁 File thực hiện

- `cores/products/BookProduct.h`
- `cores/products/BookProduct.cpp`

### 📋 Công việc

- [ ] Tạo class `BookProduct` kế thừa `Product`.
- [ ] Thêm thuộc tính:
  - `author`
  - `pages`
- [ ] Tạo constructor bằng initializer list.
- [ ] Constructor phải gọi constructor của `Product` và truyền category là `"Book"`.
- [ ] Tạo getter:
  - `getAuthor()`
  - `getPages()`
- [ ] Override 3 hàm:
  - `displayInfo()`
  - `calculateFinalPrice()`
  - `getType()`
- [ ] Test class sau khi hoàn thành.

### 💡 Logic

- `pages > 500` → giá tăng 5%.
- `pages <= 500` → giữ nguyên giá.
- `getType()` trả về `"Book"`.
- `displayInfo()` hiển thị thông tin chung của `Product` và thêm `author`, `pages`.

---

## 🎮 TASK 2 — GAME PRODUCT

**Member:** Tường Vy

### 📁 File thực hiện

- `cores/products/GameProduct.h`
- `cores/products/GameProduct.cpp`

### 📋 Công việc

- [ ] Tạo class `GameProduct` kế thừa `Product`.
- [ ] Thêm thuộc tính:
  - `platform`
  - `genre`
- [ ] Tạo constructor bằng initializer list.
- [ ] Constructor phải gọi constructor của `Product` và truyền category là `"Game"`.
- [ ] Tạo getter:
  - `getPlatform()`
  - `getGenre()`
- [ ] Override 3 hàm:
  - `displayInfo()`
  - `calculateFinalPrice()`
  - `getType()`
- [ ] Test class sau khi hoàn thành.

### 💡 Logic

- `platform == "Console"` → giá tăng 5%.
- `platform == "PC"` → giữ nguyên giá.
- `getType()` trả về `"Game"`.
- `displayInfo()` hiển thị thông tin chung của `Product` và thêm `platform`, `genre`.

---

## 🎵 TASK 3 — MUSIC PRODUCT

**Member:** Thư

### 📁 File thực hiện

- `cores/products/MusicProduct.h`
- `cores/products/MusicProduct.cpp`

### 📋 Công việc

- [ ] Tạo class `MusicProduct` kế thừa `Product`.
- [ ] Thêm thuộc tính:
  - `artist`
  - `durationMinutes`
- [ ] Tạo constructor bằng initializer list.
- [ ] Constructor phải gọi constructor của `Product` và truyền category là `"Music"`.
- [ ] Tạo getter:
  - `getArtist()`
  - `getDurationMinutes()`
- [ ] Override 3 hàm:
  - `displayInfo()`
  - `calculateFinalPrice()`
  - `getType()`
- [ ] Test class sau khi hoàn thành.

### 💡 Logic

- `durationMinutes > 60` → giá tăng 5%.
- `durationMinutes <= 60` → giữ nguyên giá.
- `getType()` trả về `"Music"`.
- `displayInfo()` hiển thị thông tin chung của `Product` và thêm `artist`, `durationMinutes`.

---

## 👤 TASK 4 — CUSTOMER

**Member:** Quang Đại

### 📁 File thực hiện

- `cores/customer/Customer.h`
- `cores/customer/Customer.cpp`

### 📋 Công việc

- [ ] Tạo class `Customer`.
- [ ] Thêm các thuộc tính:
  - `name`
  - `phone`
  - `email`
  - `address`
- [ ] Tạo constructor bằng initializer list.
- [ ] Constructor nhận đầy đủ 4 thông tin:
  - `name`
  - `phone`
  - `email`
  - `address`
- [ ] Tạo getter:
  - `getName()`
  - `getPhone()`
  - `getEmail()`
  - `getAddress()`
- [ ] Tạo setter:
  - `setName()`
  - `setPhone()`
  - `setEmail()`
  - `setAddress()`
- [ ] Tạo hàm `input()` để user nhập:
  - Personal information
  - Delivery address
- [ ] Tạo hàm `display()` để hiển thị toàn bộ thông tin Customer.
- [ ] Test constructor, getter, setter, `input()` và `display()`.

### 💡 Logic

- `Customer` lưu thông tin cá nhân của người đặt hàng.
- `address` là địa chỉ giao hàng và **bắt buộc phải có** vì được sử dụng trong flow đặt hàng.
- `input()` cho phép user nhập thông tin Customer và địa chỉ giao hàng.
- `display()` hiển thị đầy đủ:
  - Name
  - Phone
  - Email
  - Address
- Constructor nên sử dụng **initializer list**.
- Không thêm logic xử lý Order hoặc ShoppingCart vào `Customer`.

---

# 🧪 TASK 5 — TEST & NGHIỆM THU GROUP PRODUCTS

**Người phụ trách:** Hiếu Huy (Leader)

### 🎯 Mục tiêu

Kiểm tra các class `Product`, `BookProduct`, `GameProduct`, `MusicProduct` và `Customer` sau khi các member hoàn thành.

### 📁 File thực hiện

- `app/main.cpp`

### 📋 Công việc

- [ ] Ghép các class `Product`, `BookProduct`, `GameProduct`, `MusicProduct` và `Customer` để test.
- [ ] Tạo `vector<Product*>` để kiểm tra tính đa hình.
- [ ] Gọi `displayInfo()`, `calculateFinalPrice()` và `getType()` thông qua `Product*`.
- [ ] Kiểm tra cả 2 trường hợp tính giá của từng loại sản phẩm:
  - Book: `pages <= 500` và `pages > 500`.
  - Game: `PC` và `Console`.
  - Music: `durationMinutes <= 60` và `durationMinutes > 60`.
- [ ] Kiểm tra constructor, getter và `displayInfo()` của `Customer`.
- [ ] Build và chạy chương trình thành công.
- [ ] Không có lỗi compile/runtime.

### 💻 Code test mẫu

```cpp
#include "cores/products/Product.h"
#include "cores/products/BookProduct.h"
#include "cores/products/GameProduct.h"
#include "cores/products/MusicProduct.h"
#include "cores/customer/Customer.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // =========================
    // TEST BOOK
    // =========================

    BookProduct book1(
        "B001", "Clean Code", 250000, 10,
        "Robert Martin", 450
    );

    BookProduct book2(
        "B002", "C++ Primer", 300000, 8,
        "Stanley Lippman", 800
    );


    // =========================
    // TEST GAME
    // =========================

    GameProduct game1(
        "G001", "Elden Ring", 900000, 5,
        "PC", "RPG"
    );

    GameProduct game2(
        "G002", "FIFA 26", 1200000, 4,
        "Console", "Sports"
    );


    // =========================
    // TEST MUSIC
    // =========================

    MusicProduct music1(
        "M001", "Album A", 300000, 10,
        "Artist A", 55
    );

    MusicProduct music2(
        "M002", "Album B", 350000, 7,
        "Artist B", 75
    );


    // =========================
    // TEST POLYMORPHISM
    // =========================

    vector<Product*> products =
    {
        &book1,
        &book2,
        &game1,
        &game2,
        &music1,
        &music2
    };

    cout << "===== PRODUCT TEST =====\n\n";

    for (Product* product : products)
    {
        product->displayInfo();

        cout << "Gia sau tinh: "
             << product->calculateFinalPrice()
             << " VND\n";

        cout << "Loai san pham: "
             << product->getType()
             << "\n";

        cout << "-------------------------\n";
    }


    // =========================
    // TEST CUSTOMER
    // =========================

    cout << "\n===== CUSTOMER TEST =====\n\n";

    Customer customer(
        "Nguyen Van A",
        "0901234567",
        "a@gmail.com"
    );

    customer.displayInfo();

    cout << "Ten: " << customer.getName() << "\n";
    cout << "Phone: " << customer.getPhone() << "\n";
    cout << "Email: " << customer.getEmail() << "\n";


    return 0;
}