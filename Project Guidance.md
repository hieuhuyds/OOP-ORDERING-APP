# PROJECT FLOW & OOP GUIDE

## OOP Ordering Application

------------------------------------------------------------------------

# 1. Tổng quan project

## Mục tiêu

Ứng dụng cho phép người dùng:

1.  Xem danh sách sản phẩm.
2.  Tìm kiếm sản phẩm theo ID.
3.  Thêm sản phẩm vào giỏ hàng.
4.  Xem giỏ hàng.
5.  Xóa sản phẩm khỏi giỏ hàng.
6.  Checkout và nhập thông tin khách hàng.
7.  Tính tiền sản phẩm, phí vận chuyển và tổng tiền.
8.  Cập nhật stock sau khi đặt hàng.
9.  Lưu và xem lịch sử đơn hàng.

## Cấu trúc project

``` text
OOP-ORDERING-APP/
├── main.cpp
├── app/
│   ├── OrderingApplication.h
│   └── OrderingApplication.cpp
│
├── cores/
│   ├── products/
│   │   ├── Product.h
│   │   ├── Product.cpp
│   │   ├── BookProduct.h
│   │   ├── BookProduct.cpp
│   │   ├── GameProduct.h
│   │   ├── GameProduct.cpp
│   │   ├── MusicProduct.h
│   │   └── MusicProduct.cpp
│   │
│   ├── customer/
│   │   ├── Customer.h
│   │   └── Customer.cpp
│   │
│   ├── cart/
│   │   ├── CartItem.h
│   │   ├── CartItem.cpp
│   │   ├── ShoppingCart.h
│   │   └── ShoppingCart.cpp
│   │
│   └── order/
│       ├── OrderItem.h
│       ├── OrderItem.cpp
│       ├── Order.h
│       └── Order.cpp
│
├── manage/
│   ├── ProductManage.h
│   ├── ProductManage.cpp
│   ├── OrderManage.h
│   ├── OrderManage.cpp
│   ├── FileManage.h
│   └── FileManage.cpp
│
└── data/
    ├── products.txt
    └── OrderHistory.txt
```

------------------------------------------------------------------------

# 2. Class Relationship

## Sơ đồ tổng quát

``` mermaid
classDiagram

class Product {
    <<abstract>>
    #string id
    #string name
    #double price
    #int stockQuantity
    #string category
    +getId()
    +getName()
    +getPrice()
    +getStock()
    +setPrice()
    +setStock()
    +displayInfo()*
    +calculateFinalPrice()*
    +getType()*
}

class BookProduct {
    -string author
    -int pages
    +displayInfo()
    +calculateFinalPrice()
    +getType()
}

class GameProduct {
    -string platform
    -string genre
    +displayInfo()
    +calculateFinalPrice()
    +getType()
}

class MusicProduct {
    -string artist
    -int durationMinutes
    +displayInfo()
    +calculateFinalPrice()
    +getType()
}

Product <|-- BookProduct
Product <|-- GameProduct
Product <|-- MusicProduct

class Customer {
    -string name
    -string phone
    -string email
    -string address
    +input()
    +display()
}

class CartItem {
    -Product* product
    -int quantity
    +getProduct()
    +getQuantity()
    +increaseQuantity()
    +decreaseQuantity()
    +getSubtotal()
}

class ShoppingCart {
    -vector~CartItem~ items
    +addProduct()
    +removeProduct()
    +displayCart()
    +calculateSubtotal()
    +isEmpty()
    +clear()
    +getItems()
}

CartItem --> Product
ShoppingCart *-- CartItem

class OrderItem {
    -string productId
    -string productName
    -double finalPrice
    -int quantity
    +getSubtotal()
    +display()
}

class Order {
    -string orderId
    -time_t orderDate
    -time_t expectedDeliveryDate
    -Customer customer
    -string deliveryAddress
    -vector~OrderItem~ items
    -double shippingFee
    -double totalPayment
    +calculateTotal()
    +displayOrder()
}

Order *-- OrderItem
Order --> Customer

class ProductManage {
    -vector~Product*~ products
    +loadProducts()
    +saveProducts()
    +findProductById()
    +displayProducts()
    +getProducts()
}

ProductManage --> Product

class OrderManage {
    -vector~Order~ orders
    +checkout()
    +displayOrderHistory()
    +generateOrderId()
}

OrderManage --> Order
OrderManage --> ProductManage
OrderManage --> ShoppingCart

class FileManage {
    <<utility>>
    +readFile()
    +writeFile()
    +appendFile()
}

ProductManage --> FileManage
OrderManage --> FileManage

class OrderingApplication {
    -ProductManage productManage
    -OrderManage orderManage
    -ShoppingCart cart
    -Customer customer
    +run()
    +displayMenu()
    +viewProducts()
    +searchProduct()
    +addProductToCart()
    +viewCart()
    +removeProductFromCart()
    +checkout()
    +viewOrderHistory()
}

OrderingApplication --> ProductManage
OrderingApplication --> OrderManage
OrderingApplication --> ShoppingCart
OrderingApplication --> Customer
```

> **Cần nhớ:** `Product` là abstract class. `BookProduct`,
> `GameProduct`, `MusicProduct` kế thừa từ `Product`.

------------------------------------------------------------------------

# 3. Giải thích quan hệ giữa các class

## Product và các Product con

``` text
Product
├── BookProduct
├── GameProduct
└── MusicProduct
```

Đây là **inheritance**.

`Product` chứa thông tin chung:

-   ID
-   Name
-   Price
-   Stock
-   Category

Mỗi class con có thêm thông tin riêng.

Ví dụ:

-   BookProduct: Author, Pages
-   GameProduct: Platform, Genre
-   MusicProduct: Artist, Duration

`Product` có các hàm virtual:

``` cpp
virtual void displayInfo() const = 0;
virtual double calculateFinalPrice() const = 0;
virtual std::string getType() const = 0;
```

Class con override các hàm này.

------------------------------------------------------------------------

# 4. Polymorphism

Project sử dụng:

``` cpp
Product*
```

để có thể trỏ tới nhiều loại sản phẩm:

``` text
Product*
  ├── BookProduct
  ├── GameProduct
  └── MusicProduct
```

Ví dụ:

``` cpp
Product* product = new BookProduct(...);
product->displayInfo();
```

Do `displayInfo()` là virtual, chương trình gọi phiên bản của
`BookProduct`.

Tương tự:

``` cpp
product->calculateFinalPrice();
```

sẽ gọi đúng cách tính giá của loại sản phẩm thực tế.

Đây là **runtime polymorphism**.

------------------------------------------------------------------------

# 5. CartItem và Product\*

`CartItem` chứa:

``` cpp
Product* product;
int quantity;
```

Tại sao dùng pointer?

Vì CartItem chỉ cần **tham chiếu đến Product đang được quản lý bởi
ProductManage**, không cần tạo một Product mới.

Ví dụ:

``` text
ProductManage
     |
     | Product*
     v
  Product
     ^
     |
 CartItem
```

`CartItem` không sở hữu Product nên **không delete Product**.

Product được quản lý và giải phóng bởi `ProductManage`.

------------------------------------------------------------------------

# 6. ShoppingCart

`ShoppingCart` chứa:

``` cpp
std::vector<CartItem> items;
```

Mỗi phần tử trong vector là một `CartItem`.

``` text
ShoppingCart
    |
    +-- CartItem
    +-- CartItem
    +-- CartItem
```

Khi thêm cùng một sản phẩm:

``` text
B001 x 2
B001 x 3
```

không tạo hai CartItem.

Kết quả:

``` text
B001 x 5
```

ShoppingCart cũng kiểm tra quantity không được vượt stock.

------------------------------------------------------------------------

# 7. OrderItem và Order

Khi checkout, thông tin sản phẩm được đưa vào `OrderItem`.

`OrderItem` lưu:

-   Product ID
-   Product Name
-   Final Price
-   Quantity
-   Subtotal

Điểm quan trọng:

`OrderItem` không giữ `Product*`.

Nó lưu thông tin cần thiết của sản phẩm tại thời điểm đặt hàng.

``` text
ShoppingCart
     |
     | checkout
     v
OrderItem
     |
     v
Order
```

`Order` chứa:

``` cpp
std::vector<OrderItem> items;
```

------------------------------------------------------------------------

# 8. Customer và Order

`Customer` lưu thông tin người mua:

``` text
Name
Phone
Email
Address
```

Khi checkout:

``` text
Customer
    +
ShoppingCart
    +
ProductManage
    |
    v
OrderManage
    |
    v
Order
```

`Order` lưu Customer và delivery address của đơn hàng.

------------------------------------------------------------------------

# 9. ProductManage

`ProductManage` quản lý danh sách Product:

``` cpp
std::vector<Product*> products;
```

Nó chịu trách nhiệm:

-   Load sản phẩm từ `products.txt`.
-   Tạo đúng loại Product.
-   Tìm sản phẩm theo ID.
-   Hiển thị sản phẩm.
-   Save sản phẩm.
-   Delete các Product\* khi destructor chạy.

Ví dụ file:

``` text
BOOK|B001|Clean Code|250000|10|Robert Martin|450
GAME|G001|Elden Ring|900000|5|PC|RPG
MUSIC|M001|Album A|300000|10|Artist A|55
```

ProductManage đọc `BOOK`, `GAME`, `MUSIC` rồi tạo object tương ứng.

------------------------------------------------------------------------

# 10. FileManage

`FileManage` cung cấp các thao tác file chung:

``` cpp
readFile()
writeFile()
appendFile()
```

Nó không quyết định dữ liệu là Product hay Order.

Nó chỉ chịu trách nhiệm đọc/ghi file.

Ví dụ:

``` text
ProductManage
      |
      v
  FileManage
      |
      v
products.txt
```

và:

``` text
OrderManage
      |
      v
  FileManage
      |
      v
OrderHistory.txt
```

------------------------------------------------------------------------

# 11. OrderingApplication

`OrderingApplication` là nơi điều khiển chương trình.

Nó không nên tự xử lý tất cả logic.

Nhiệm vụ chính:

-   Hiển thị menu.
-   Nhận lựa chọn của người dùng.
-   Gọi đúng manager/class.
-   Điều phối các module.

Ví dụ:

``` text
User
 ↓
OrderingApplication
 ↓
ProductManage / ShoppingCart / OrderManage
 ↓
Các module xử lý
```

------------------------------------------------------------------------

# 12. PROGRAM FLOW

## Flow tổng quát

``` mermaid
flowchart TD
    A[Start] --> B[Create OrderingApplication]
    B --> C[Load products.txt]
    C --> D[Display Menu]
    D --> E{User Choice}

    E -->|1| F[View Products]
    F --> D

    E -->|2| G[Search Product]
    G --> D

    E -->|3| H[Add Product To Cart]
    H --> D

    E -->|4| I[View Cart]
    I --> D

    E -->|5| J[Remove Product From Cart]
    J --> D

    E -->|6| K[Checkout]
    K --> D

    E -->|7| L[View Order History]
    L --> D

    E -->|0| M[Exit]
```

------------------------------------------------------------------------

# 13. Chi tiết flow Checkout

``` mermaid
flowchart TD
    A[Choose Checkout] --> B{Cart empty?}
    B -->|Yes| C[Show empty cart message]
    C --> Z[Return to menu]

    B -->|No| D[Input Customer Information]
    D --> E[Check Product Stock]
    E --> F{Stock valid?}

    F -->|No| G[Cancel checkout]
    G --> Z

    F -->|Yes| H[Create OrderItem]
    H --> I[Generate Order ID]
    I --> J[Create Order]
    J --> K[Calculate Shipping Fee]
    K --> L[Calculate Total Payment]
    L --> M[Decrease Product Stock]
    M --> N[Save products.txt]
    N --> O[Save OrderHistory.txt]
    O --> P[Clear Cart]
    P --> Q[Display Order]
    Q --> Z
```

## Quy tắc checkout

### Stock

Nếu quantity đặt mua lớn hơn stock:

``` text
Checkout thất bại
```

Không được:

-   tạo Order
-   giảm stock
-   clear cart

### Shipping

``` text
Subtotal < 500000
→ Shipping = 30000

Subtotal >= 500000
→ Shipping = 0
```

### Total

``` text
Total = Subtotal + Shipping
```

------------------------------------------------------------------------

# 14. Flow tính giá

Giá trong `products.txt` là **base price**.

Ví dụ:

``` text
B002
Base price = 300000
Pages = 800
```

Book có hơn 500 pages:

``` text
Final price = 300000 × 1.05
            = 315000
```

Tương tự:

``` text
Game Console → +5%
Game PC → base price

Music duration > 60 → +5%
Music duration <= 60 → base price
```

`calculateFinalPrice()` trả về giá cuối cùng của sản phẩm.

Shipping không nằm trong `calculateFinalPrice()`.

Shipping được xử lý riêng trong `Order`.

------------------------------------------------------------------------

# 15. Kiến thức C++ được áp dụng

## 15.1 Class và Object

Các class chính:

``` text
Product
BookProduct
GameProduct
MusicProduct
Customer
CartItem
ShoppingCart
OrderItem
Order
ProductManage
OrderManage
FileManage
OrderingApplication
```

Các object được tạo từ những class này để quản lý dữ liệu và hành vi.

------------------------------------------------------------------------

# 16. Encapsulation

Các thuộc tính được đặt `private` hoặc `protected`.

Ví dụ:

``` cpp
private:
    std::string name;
    std::string phone;
```

Muốn truy cập dữ liệu thì dùng getter/setter:

``` cpp
getName()
getPhone()
setName()
setPhone()
```

Mục đích:

-   Bảo vệ dữ liệu.
-   Không cho code bên ngoài thay đổi trực tiếp tùy ý.
-   Gom dữ liệu và hành vi vào class.

------------------------------------------------------------------------

# 17. Inheritance

Các class:

``` text
Product
├── BookProduct
├── GameProduct
└── MusicProduct
```

Class con kế thừa các thuộc tính và interface chung của Product.

Ví dụ:

``` cpp
class BookProduct : public Product
```

Lợi ích:

-   Không phải viết lại các thuộc tính chung.
-   Các loại Product có thể dùng chung interface.

------------------------------------------------------------------------

# 18. Abstraction

`Product` là abstract class vì có pure virtual function:

``` cpp
virtual void displayInfo() const = 0;
virtual double calculateFinalPrice() const = 0;
virtual std::string getType() const = 0;
```

Không thể tạo:

``` cpp
Product product;
```

Mà phải tạo class cụ thể:

``` cpp
BookProduct
GameProduct
MusicProduct
```

Product chỉ định nghĩa interface chung.

------------------------------------------------------------------------

# 19. Virtual

`virtual` cho phép chương trình gọi đúng hàm override của object thực
tế.

Ví dụ:

``` cpp
Product* product = new GameProduct(...);

product->calculateFinalPrice();
```

Chương trình sẽ gọi:

``` cpp
GameProduct::calculateFinalPrice()
```

thay vì hàm của Product.

Đây là nền tảng của polymorphism.

------------------------------------------------------------------------

# 20. Pointer

Project dùng:

``` cpp
Product*
```

ở những nơi cần làm việc với nhiều loại Product khác nhau.

Ví dụ:

``` cpp
std::vector<Product*> products;
```

ProductManage có thể chứa:

``` text
BookProduct*
GameProduct*
MusicProduct*
```

thông qua kiểu chung:

``` cpp
Product*
```

### Tại sao không dùng `Product` trực tiếp?

Vì Product là abstract class và cần polymorphism.

------------------------------------------------------------------------

# 21. Reference

Project sử dụng reference để tránh copy dữ liệu không cần thiết.

Ví dụ:

``` cpp
for (auto& item : items)
```

`item` là reference tới phần tử thật trong vector.

Vì vậy:

``` cpp
item.increaseQuantity(quantity);
```

sẽ thay đổi CartItem thật trong vector.

Nếu dùng:

``` cpp
for (auto item : items)
```

thì `item` là bản copy.

------------------------------------------------------------------------

# 22. const

`const` được dùng khi hàm không thay đổi object.

Ví dụ:

``` cpp
void displayCart() const;
```

Hàm này chỉ hiển thị dữ liệu, không thay đổi ShoppingCart.

Getter cũng thường dùng:

``` cpp
std::string getName() const;
```

Điều này giúp thể hiện rõ ý định của hàm và hạn chế thay đổi dữ liệu
ngoài ý muốn.

------------------------------------------------------------------------

# 23. const reference

`getItems()`:

``` cpp
const std::vector<CartItem>& getItems() const;
```

Có hai phần quan trọng:

### `&`

Không copy toàn bộ vector.

### `const`

Code nhận vector chỉ có thể đọc, không thể sửa trực tiếp.

Ví dụ:

``` text
vector lớn
   ↓
reference → không copy
   ↓
const → chỉ đọc
```

------------------------------------------------------------------------

# 24. vector

Project dùng:

``` cpp
std::vector
```

để quản lý danh sách có số lượng phần tử thay đổi.

Ví dụ:

``` cpp
std::vector<CartItem> items;
std::vector<Order> orders;
std::vector<Product*> products;
```

Lý do dùng vector:

-   Không cần biết trước số lượng phần tử.
-   Dễ thêm/xóa phần tử.
-   Dễ duyệt bằng vòng lặp.
-   Phù hợp với danh sách Product, CartItem và Order.

------------------------------------------------------------------------

# 25. Iterator

Khi xóa Product khỏi cart:

``` cpp
for (auto it = items.begin(); it != items.end(); ++it)
{
    if (it->getProduct()->getId() == productId)
    {
        items.erase(it);
        return true;
    }
}
```

`it` là iterator trỏ tới phần tử hiện tại trong vector.

``` text
items
 ↓
[CartItem] [CartItem] [CartItem]
     ↑
    it
```

`it->` dùng để truy cập CartItem mà iterator đang trỏ tới.

------------------------------------------------------------------------

# 26. Constructor và Member Initializer List

Constructor được dùng để khởi tạo object.

Ví dụ:

``` cpp
CartItem::CartItem(Product* product, int quantity)
    : product(product),
      quantity(quantity < 0 ? 0 : quantity)
{
}
```

Member initializer list khởi tạo member ngay khi object được tạo.

Đây là cách phù hợp để khởi tạo dữ liệu thành viên.

------------------------------------------------------------------------

# 27. Destructor và Memory Management

`ProductManage` chứa:

``` cpp
std::vector<Product*> products;
```

Các Product được tạo động bằng `new`.

Vì vậy ProductManage phải giải phóng chúng trong destructor:

``` cpp
ProductManage::~ProductManage()
{
    for (Product* product : products)
    {
        delete product;
    }
}
```

CartItem chỉ giữ pointer tới Product nên **không được delete Product
trong CartItem**.

Điều này tránh:

-   Memory leak.
-   Double delete.

------------------------------------------------------------------------

# 28. File I/O

Project dùng:

``` cpp
std::ifstream
std::ofstream
std::fstream
```

để đọc/ghi file.

Ví dụ:

``` text
products.txt
```

dùng để lưu Product.

``` text
OrderHistory.txt
```

dùng để lưu Order History.

`FileManage` gom các thao tác file dùng chung để các manager không phải
lặp lại code đọc/ghi file.

------------------------------------------------------------------------

# 29. String Stream và Parsing

Product file dùng dấu `|` để phân cách dữ liệu:

``` text
BOOK|B001|Clean Code|250000|10|Robert Martin|450
```

Code sử dụng:

``` cpp
std::istringstream
```

và:

``` cpp
std::getline(iss, value, '|');
```

để tách từng trường.

Ví dụ:

``` text
BOOK
B001
Clean Code
250000
10
Robert Martin
450
```

------------------------------------------------------------------------

# 30. Conversion String

Khi dữ liệu đọc từ file đang ở dạng string:

``` cpp
std::string priceStr;
std::string stockStr;
```

cần chuyển sang số:

``` cpp
std::stod(priceStr);
std::stoi(stockStr);
```

-   `stod`: string → double
-   `stoi`: string → int
-   `stoll`: string → long long

------------------------------------------------------------------------

# 31. Date và Time

Order lấy thời gian hệ thống:

``` cpp
std::time(nullptr)
```

Sau đó chuyển sang thời gian local bằng:

``` cpp
localtime_s(...)
```

Ngày đặt hàng được lưu dưới dạng timestamp trong file.

Expected delivery:

``` text
Order date + 3 days
```

Khi hiển thị, timestamp được format thành:

``` text
dd/mm/yyyy
```

Ví dụ:

``` text
11/09/2026
14/09/2026
```

------------------------------------------------------------------------

# 32. Static Function

`FileManage` có các hàm static:

``` cpp
static bool readFile(...);
static bool writeFile(...);
static bool appendFile(...);
```

Có thể gọi trực tiếp:

``` cpp
FileManage::readFile(...);
```

Không cần tạo object FileManage.

Lý do: FileManage chỉ cung cấp các thao tác file dùng chung và không cần
lưu state riêng cho từng object.

------------------------------------------------------------------------

# 33. Exception / Validation

Project chủ yếu dùng validation đơn giản bằng `if`.

Ví dụ:

``` cpp
if (product == nullptr)
```

``` cpp
if (quantity <= 0)
```

``` cpp
if (quantity > product->getStock())
```

Mục tiêu là chặn dữ liệu không hợp lệ trước khi thực hiện thao tác tiếp
theo.

------------------------------------------------------------------------

# 34. Phân chia trách nhiệm

## Product

Quản lý thông tin chung của Product và interface chung.

## BookProduct / GameProduct / MusicProduct

Quản lý thông tin riêng và cách tính final price của từng loại.

## Customer

Quản lý thông tin khách hàng.

## CartItem

Đại diện cho một sản phẩm và số lượng trong cart.

## ShoppingCart

Quản lý danh sách CartItem và subtotal.

## OrderItem

Lưu snapshot thông tin Product trong đơn hàng.

## Order

Quản lý thông tin một đơn hàng, shipping và total.

## ProductManage

Quản lý danh sách Product và file Product.

## OrderManage

Quản lý checkout, Order ID, stock và Order History.

## FileManage

Cung cấp thao tác đọc/ghi file chung.

## OrderingApplication

Điều khiển menu và kết nối các module.

------------------------------------------------------------------------

# 35. Flow hoàn chỉnh cần mỗi thành viên hiểu

Mỗi thành viên nên có thể giải thích flow này mà không cần nhìn code:

``` text
main()
  ↓
OrderingApplication::run()
  ↓
load products.txt
  ↓
display menu
  ↓
User chooses function
  ↓
View / Search / Add / Remove / Checkout / History
```

Nếu checkout:

``` text
Checkout
  ↓
Check cart
  ↓
Input Customer
  ↓
Check stock
  ↓
Create OrderItem
  ↓
Generate Order ID
  ↓
Create Order
  ↓
Calculate subtotal
  ↓
Calculate shipping
  ↓
Calculate total
  ↓
Decrease stock
  ↓
Save products.txt
  ↓
Save OrderHistory.txt
  ↓
Clear cart
  ↓
Display order
```

------------------------------------------------------------------------

# 36. Câu hỏi giáo viên có thể hỏi

## Câu 1: Tại sao Product là abstract class?

**Trả lời:**

Vì Product chỉ mô tả interface chung cho các loại sản phẩm. Mỗi loại như
Book, Game và Music có cách hiển thị và tính final price khác nhau nên
Product dùng pure virtual function để class con tự implement.

------------------------------------------------------------------------

## Câu 2: Tại sao dùng virtual?

**Trả lời:**

Để hỗ trợ runtime polymorphism. Khi Product\* trỏ tới BookProduct,
GameProduct hoặc MusicProduct thì gọi `displayInfo()` hoặc
`calculateFinalPrice()` sẽ chạy đúng phiên bản của class thực tế.

------------------------------------------------------------------------

## Câu 3: Tại sao dùng Product\*?

**Trả lời:**

Vì Product là abstract class và Product\* cho phép ProductManage hoặc
CartItem làm việc với nhiều loại Product thông qua cùng một interface.

------------------------------------------------------------------------

## Câu 4: Tại sao CartItem không delete Product\*?

**Trả lời:**

Vì CartItem chỉ tham chiếu đến Product đang được ProductManage quản lý,
không sở hữu Product. ProductManage chịu trách nhiệm giải phóng Product
để tránh double delete.

------------------------------------------------------------------------

## Câu 5: Tại sao dùng vector?

**Trả lời:**

Vì số lượng Product, CartItem và Order không cố định. Vector cho phép
lưu danh sách động và dễ thêm, xóa, duyệt phần tử.

------------------------------------------------------------------------

## Câu 6: Tại sao dùng reference trong `for (auto& item : items)`?

**Trả lời:**

Để làm việc trực tiếp với phần tử trong vector, tránh copy CartItem. Vì
vậy khi gọi `item.increaseQuantity()` thì CartItem thật được thay đổi.

------------------------------------------------------------------------

## Câu 7: Tại sao dùng const?

**Trả lời:**

Những hàm chỉ đọc dữ liệu được đánh dấu const để đảm bảo hàm không thay
đổi object. Ví dụ `displayCart() const`.

------------------------------------------------------------------------

## Câu 8: Tại sao `getItems()` trả về const reference?

**Trả lời:**

Để tránh copy toàn bộ vector và chỉ cho bên ngoài đọc dữ liệu, không cho
sửa trực tiếp vector của ShoppingCart.

------------------------------------------------------------------------

## Câu 9: Tại sao OrderItem không dùng Product\*?

**Trả lời:**

OrderItem lưu thông tin sản phẩm tại thời điểm đặt hàng như ID, name,
final price và quantity. Điều này giúp đơn hàng giữ lại thông tin của
sản phẩm tại thời điểm mua.

------------------------------------------------------------------------

## Câu 10: Final price khác base price như thế nào?

**Trả lời:**

Base price là giá ban đầu lưu trong products.txt. Final price là giá sau
khi áp dụng rule riêng của từng loại Product.

Ví dụ Book hơn 500 pages thì final price tăng 5%.

------------------------------------------------------------------------

## Câu 11: Shipping có nằm trong calculateFinalPrice() không?

**Trả lời:**

Không. `calculateFinalPrice()` chỉ tính giá cuối của một sản phẩm.
Shipping được tính riêng trong Order dựa trên subtotal.

------------------------------------------------------------------------

## Câu 12: Nếu quantity lớn hơn stock thì sao?

**Trả lời:**

Không cho thêm vào cart hoặc checkout. Khi checkout thất bại thì không
tạo Order, không giảm stock và không clear cart.

------------------------------------------------------------------------

## Câu 13: Tại sao cần OrderManage?

**Trả lời:**

Để tách logic quản lý Order khỏi OrderingApplication. OrderManage xử lý
checkout, tạo Order ID, cập nhật stock và lưu Order History.

------------------------------------------------------------------------

## Câu 14: Tại sao cần FileManage?

**Trả lời:**

Để gom các thao tác đọc, ghi và append file dùng chung. ProductManage và
OrderManage có thể sử dụng lại thay vì viết lại code file I/O.

------------------------------------------------------------------------

## Câu 15: `std::time(nullptr)` dùng để làm gì?

**Trả lời:**

Lấy thời gian hệ thống hiện tại để làm ngày đặt hàng.

------------------------------------------------------------------------

## Câu 16: Expected delivery được tính thế nào?

**Trả lời:**

Expected delivery bằng ngày đặt hàng cộng thêm 3 ngày.

------------------------------------------------------------------------

## Câu 17: Destructor ProductManage để làm gì?

**Trả lời:**

ProductManage chứa Product\* được tạo động, nên destructor delete từng
Product để giải phóng bộ nhớ và tránh memory leak.

------------------------------------------------------------------------

## Câu 18: `it` trong removeProduct là gì?

**Trả lời:**

`it` là iterator dùng để duyệt từng phần tử trong vector. `it->` cho
phép truy cập CartItem mà iterator đang trỏ tới.

------------------------------------------------------------------------

## Câu 19: Tại sao dùng initializer list?

**Trả lời:**

Để khởi tạo member ngay khi object được tạo. Đây là cách phù hợp và rõ
ràng để khởi tạo các member của class.

------------------------------------------------------------------------

## Câu 20: OrderingApplication có làm tất cả logic không?

**Trả lời:**

Không. OrderingApplication chủ yếu điều khiển menu và gọi các module.
Logic Product nằm ở Product/ProductManage, cart nằm ở ShoppingCart, còn
checkout và Order History nằm ở OrderManage.

------------------------------------------------------------------------

# 37. Những điều không nên trả lời sai

### Không nói:

> Product chứa tất cả loại Product.

Nên nói:

> Product là abstract base class, các loại cụ thể là BookProduct,
> GameProduct và MusicProduct.

### Không nói:

> CartItem sở hữu Product.

Nên nói:

> CartItem chỉ giữ Product\* để tham chiếu đến Product được
> ProductManage quản lý.

### Không nói:

> calculateFinalPrice() bao gồm shipping.

Nên nói:

> calculateFinalPrice() chỉ tính final price của Product; shipping được
> tính riêng trong Order.

### Không nói:

> OrderingApplication xử lý toàn bộ nghiệp vụ.

Nên nói:

> OrderingApplication điều phối các module; nghiệp vụ được chia cho các
> class tương ứng.

------------------------------------------------------------------------

# 38. Checklist trước khi thuyết trình

Mỗi thành viên phải tự giải thích được:

-   [ ] Project có những class nào?
-   [ ] Product có những class con nào?
-   [ ] Abstract class là gì?
-   [ ] Pure virtual function là gì?
-   [ ] Virtual dùng để làm gì?
-   [ ] Polymorphism nằm ở đâu?
-   [ ] Product\* dùng ở đâu và tại sao?
-   [ ] `vector<Product*>` dùng để làm gì?
-   [ ] CartItem liên kết với Product thế nào?
-   [ ] ShoppingCart quản lý CartItem thế nào?
-   [ ] OrderItem khác CartItem thế nào?
-   [ ] Order lưu những gì?
-   [ ] Customer được dùng lúc nào?
-   [ ] ProductManage làm gì?
-   [ ] OrderManage làm gì?
-   [ ] FileManage làm gì?
-   [ ] `const` dùng ở đâu?
-   [ ] Reference dùng ở đâu?
-   [ ] Vì sao dùng `const vector<CartItem>&`?
-   [ ] Stock được kiểm tra ở đâu?
-   [ ] Shipping được tính thế nào?
-   [ ] Final price khác base price thế nào?
-   [ ] Order ID được tạo thế nào?
-   [ ] Order History lưu ở đâu?
-   [ ] Vì sao cần destructor?
-   [ ] Nếu checkout thất bại thì chuyện gì xảy ra?
-   [ ] Flow từ `main()` đến checkout như thế nào?

------------------------------------------------------------------------

# 39. Câu trả lời ngắn gọn khi giáo viên yêu cầu mô tả project

> Đây là một ứng dụng Ordering Application viết bằng C++. Project sử
> dụng OOP để quản lý sản phẩm, khách hàng, giỏ hàng và đơn hàng.
> `Product` là abstract class, được kế thừa bởi `BookProduct`,
> `GameProduct` và `MusicProduct`. Project sử dụng inheritance,
> abstraction, encapsulation và polymorphism. `Product*` được dùng để
> làm việc với nhiều loại Product thông qua cùng một interface.
> `ShoppingCart` quản lý các `CartItem`, còn `OrderManage` xử lý
> checkout, cập nhật stock và lưu Order History. `FileManage` cung cấp
> các thao tác đọc và ghi file dùng chung. `OrderingApplication` đóng
> vai trò điều khiển menu và kết nối các module.

------------------------------------------------------------------------

# 40. Một câu quan trọng cần nhớ

``` text
OrderingApplication = Điều khiển chương trình
Product/Product con = Quản lý sản phẩm
ProductManage = Quản lý danh sách sản phẩm + file sản phẩm
Customer = Thông tin khách hàng
CartItem = Một sản phẩm trong cart
ShoppingCart = Quản lý cart
OrderItem = Một sản phẩm trong order
Order = Một đơn hàng
OrderManage = Quản lý checkout + order history
FileManage = Đọc/ghi file
```

Nếu mỗi thành viên hiểu được phần này và giải thích được lý do sử dụng
`pointer`, `reference`, `const`, `vector`, `virtual`, thì nhóm có thể tự
tin giải thích toàn bộ project thay vì chỉ biết module mình được giao.
