# TASK CÒN LẠI 9.9 - DEADLINE 12H TRƯA 10.9

## TASK 10 — ProductManage   - Tường Vy

**File:**
- `manage/ProductManage.h`
- `manage/ProductManage.cpp`

**Cần làm:**
- Dùng `std::vector<Product*> products`.
- `~ProductManage()`.
- `void loadProducts(const std::string& filename)`.
- `bool saveProducts(const std::string& filename) const`.
- `Product* findProductById(const std::string& productId) const`.
- `void displayProducts() const`.
- `const std::vector<Product*>& getProducts() const`.
- Đọc dữ liệu từ `data/products.txt`.
- `BOOK` → tạo `BookProduct`.
- `GAME` → tạo `GameProduct`.
- `MUSIC` → tạo `MusicProduct`.
- Lưu các object vào `products`.
- Tìm sản phẩm theo Product ID.
- Hiển thị danh sách sản phẩm.
- Ghi lại dữ liệu vào `products.txt`.
- Destructor giải phóng các `Product*`.

**Logic:**
- Không tìm thấy Product ID → trả về `nullptr`.
- `displayProducts()` gọi `displayInfo()` của từng Product để thể hiện đa hình.
- `saveProducts()` phải giữ đúng format của `products.txt`.
- Khi save phải ghi đúng dữ liệu riêng của `BookProduct`, `GameProduct`, `MusicProduct`.
- Không để memory leak.
- Không cho copy `ProductManage` để tránh shallow copy và double free.

**Lưu ý format `products.txt`:**
- Đây là format dữ liệu bắt buộc khi `loadProducts()` đọc file và `saveProducts()` ghi file.
- Dùng dấu `|` để ngăn cách các trường.
- Không có header.
- Format chung:
  `TYPE|ID|NAME|PRICE|STOCK|ATTRIBUTE1|ATTRIBUTE2`
- `BOOK` → `BOOK|ID|NAME|PRICE|STOCK|AUTHOR|PAGES`
- `GAME` → `GAME|ID|NAME|PRICE|STOCK|PLATFORM|GENRE`
- `MUSIC` → `MUSIC|ID|NAME|PRICE|STOCK|ARTIST|DURATION`
- Khi `loadProducts()` phải đọc đúng thứ tự field trên.
- Khi `saveProducts()` phải ghi đúng thứ tự field và đúng format trên.

**Lưu ý code style:**
- Có `#pragma once` trong `.h`.
- Không dùng `using namespace std;`.
- Dùng `std::vector`, `std::string`,...
- Có thể thêm:
  `ProductManage(const ProductManage&) = delete;`
  `ProductManage& operator=(const ProductManage&) = delete;`
- Không tự thêm chức năng ngoài task.

**Test:**
- [ ] Load được `products.txt`.
- [ ] Tạo đúng `BookProduct`, `GameProduct`, `MusicProduct`.
- [ ] Search đúng Product ID.
- [ ] Search ID không tồn tại → `nullptr`.
- [ ] `displayProducts()` hiển thị đúng.
- [ ] `saveProducts()` ghi đúng format.
- [ ] Thay đổi stock → save lại đúng file.
- [ ] Destructor giải phóng Product.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

## TASK 11 — OrderManage - Minh Tiến

**File:**
- `manage/OrderManage.h`
- `manage/OrderManage.cpp`

**Cần làm:**
- Dùng `std::vector<Order> orders`.
- `bool checkout(const Customer& customer, ShoppingCart& cart, ProductManage& productManage)`.
- `void displayOrderHistory() const`.
- `std::string generateOrderId() const`.
- Quản lý danh sách `Order`.
- Xử lý checkout.
- Từ các `CartItem` tạo `OrderItem`.
- Tạo `Order`.
- Lưu đơn vào `data/OrderHistory.txt`.

**Logic:**
- Nếu cart rỗng → checkout thất bại.
- Trước khi checkout, kiểm tra tồn kho của tất cả sản phẩm trong cart.
- Với mỗi `CartItem`:
  - Lấy Product tương ứng.
  - Kiểm tra Product có tồn tại.
  - Kiểm tra `quantity <= stock`.
- Nếu có sản phẩm không tồn tại hoặc không đủ stock:
  - Checkout thất bại.
  - Không tạo Order.
  - Không trừ stock.
  - Không clear cart.
- Nếu tất cả hợp lệ:
  - Tạo `OrderItem`.
  - Sinh OrderID.
  - Tạo `Order`.
  - Gọi `calculateTotal()`.
  - Trừ stock Product.
  - Gọi `productManage.saveProducts(...)`.
  - Lưu Order vào `OrderHistory.txt`.
  - `cart.clear()` sau khi checkout thành công.
- Dùng `FileManage` để ghi file.
- Không `delete Product`.

**Quy ước OrderID:**
- Prefix: `DH`.
- 3 chữ số phía sau.
- Ví dụ:
  - `DH001`
  - `DH002`
  - `DH003`
- Không được trùng OrderID cũ.
- Khi restart app, OrderID phải tiếp tục tăng.
- Không dùng `orders.size()` đơn thuần để sinh mã.
- Có thể đọc `OrderHistory.txt` để tìm số lớn nhất hiện tại rồi tăng lên `1`.

**Lưu ý code style:**
- Có `#pragma once` trong `.h`.
- Không dùng `using namespace std;`.
- Dùng `std::vector`, `std::string`,...
- Không tự viết lại logic subtotal/shipping của `Order`.
- Không thêm payment/admin.
- Không tự thêm chức năng ngoài task.

**Lưu ý format `OrderHistory.txt`:**
- Mỗi Order lưu thành một record trong file.
- Dùng dấu `|` để ngăn cách các field.
- OrderID theo dạng:
  `DH001`, `DH002`, `DH003`,...
- `OrderDate` và `ExpectedDeliveryDate` hiển thị theo format `dd/mm/yyyy`.
- Phần danh sách sản phẩm phải lưu đủ thông tin để có thể đọc lại và hiển thị được bill.
- Không tự đổi thứ tự field hoặc tự tạo format khác.
- `displayOrderHistory()` phải đọc đúng format đã lưu và hiển thị từng Order bằng `Order::displayOrder()`.

**Test:**
- [ ] Cart rỗng → checkout thất bại.
- [ ] Product không tồn tại → checkout thất bại.
- [ ] Quantity vượt stock → checkout thất bại.
- [ ] Checkout lỗi → stock không đổi.
- [ ] Checkout lỗi → cart không bị clear.
- [ ] Checkout thành công.
- [ ] OrderID đúng dạng `DH001`, `DH002`,...
- [ ] Restart app → OrderID tiếp tục tăng.
- [ ] `OrderItem` đúng dữ liệu.
- [ ] Total đúng.
- [ ] Stock giảm đúng.
- [ ] `products.txt` được cập nhật.
- [ ] `OrderHistory.txt` lưu được đơn.
- [ ] Cart được clear sau checkout.
 
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

## TASK 12 — OrderingApplication ------- 2 Thành viên thực hiện: (Thành viên 3: Quang Đại) + (Thành viên 4: Thư)


**Lưu ý giao diện/menu:**
- Menu dùng tiếng Anh và giữ thống nhất:
  `1 → View products`
  `2 → Search product`
  `3 → Add product to cart`
  `4 → View cart`
  `5 → Remove product from cart`
  `6 → Checkout`
  `7 → View order history`
  `0 → Exit`
- `OrderingApplication` chỉ điều phối và gọi các module, không tự xử lý format file.
- `7 → View order history` phải gọi `OrderManage::displayOrderHistory()`.
- Bill được hiển thị thông qua `Order::displayOrder()`.

### Interface / Signature cuối cùng của OrderingApplication

class OrderingApplication
{
private:
    ProductManage productManage;
    OrderManage orderManage;
    ShoppingCart cart;
    Customer customer;

    void addProductToCart();
    void viewCart() const;
    void removeProductFromCart();
    void checkout();
    void viewOrderHistory() const;

public:
    void run();
    void displayMenu() const;
    void viewProducts() const;
    void searchProduct() const;
};

**File:**
- `app/OrderingApplication.h`
- `app/OrderingApplication.cpp`

**Chia công việc:**

### Thành viên 3 — Menu + Product + Cart - Quang Đại

**Phụ trách:**
- `run()`
- `displayMenu()`
- `viewProducts()`
- `searchProduct()`
- `addProductToCart()`
- `viewCart()`
- `removeProductFromCart()`

**Signature:**
- `void run()`
- `void displayMenu() const`
- `void viewProducts() const`
- `void searchProduct() const`
- `void addProductToCart()`
- `void viewCart() const`
- `void removeProductFromCart()`

**Logic:**
- Khi app khởi động → gọi `productManage.loadProducts("data/products.txt")`.
- `1` → View products.
- `2` → Search product.
- `3` → Add product to cart.
- `4` → View cart.
- `5` → Remove product from cart.
- `6` → gọi `checkout()`.
- `7` → gọi `viewOrderHistory()`.
- `0` → thoát.

**Chi tiết:**
- `viewProducts()` → gọi `productManage.displayProducts()`.
- `searchProduct()` → nhập Product ID → gọi `productManage.findProductById()`.
- Nếu tìm thấy → `displayInfo()`.
- `addProductToCart()` → nhập Product ID + quantity → tìm Product → gọi `cart.addProduct()`.
- `viewCart()` → gọi `cart.displayCart()`.
- `removeProductFromCart()` → nhập Product ID → gọi `cart.removeProduct()`.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

**Quy định Git Cho Quang Đại (Thành viên 3) và Thư (Thành viên 4):**
- Thành viên 3 (Quang Đại) dựng trước khung `OrderingApplication.h/.cpp`.
- Thành viên 3 (Quang Đại) viết `run()`, `displayMenu()` và switch menu `0 → 7`.
- Sau khi dựng khung → commit/push.
- Thành viên 4 (Thư) pull source mới nhất rồi mới code phần checkout/history.
- Sau khi khung đã chốt, không sửa lại `run()` và `displayMenu()`.
- Không tạo `OrderingApplication2`.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

**Test:**
- [ ] Load products.
- [ ] View products.
- [ ] Search đúng Product ID.
- [ ] Search sai Product ID.
- [ ] Add product vào cart.
- [ ] View cart.
- [ ] Remove product khỏi cart.

---

### Thành viên 4 — Checkout + Order History - Thư

**Phụ trách:**
- `checkout()`
- `viewOrderHistory()`

**Signature:**
- `void checkout()`
- `void viewOrderHistory() const`

**Logic:**
- `6` → gọi `checkout()`.
- Trong `checkout()`:
  - Kiểm tra cart.
  - Nhập thông tin Customer:
    - Name
    - Phone
    - Email
    - Address
  - Có thể dùng `Customer::input()` nếu class đã có method này.
  - Gọi:
    `orderManage.checkout(customer, cart, productManage)`.
- `7` → gọi `viewOrderHistory()`.
- `viewOrderHistory()` → gọi:
  `orderManage.displayOrderHistory()`.

**Lưu ý:**
- Không tự tính subtotal.
- Không tự tính shipping.
- Không tự trừ stock.
- Không tự ghi `OrderHistory.txt`.
- Không sửa lại `run()` và `displayMenu()`.
- Không tạo file `OrderingApplication` thứ hai.
- Không dùng `using namespace std;`.
- Dùng `std::`.

**Test:**
- [ ] Checkout khi cart rỗng.
- [ ] Checkout khi thiếu stock.
- [ ] Checkout thành công.
- [ ] Nhập đủ Name, Phone, Email, Address.
- [ ] OrderID được tạo.
- [ ] Stock giảm.
- [ ] `products.txt` cập nhật.
- [ ] `OrderHistory.txt` lưu đơn.
- [ ] Cart được clear.
- [ ] View order history.