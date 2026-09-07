# 📋 TASK CẦN LÀM — OOP ORDERING APPLICATION

> 📅 Ngày làm: **07/09**
> ⏰ Deadline: **12:00 trưa 08/09**

## 🎯 Mục tiêu

Hoàn thành các module Cart → Order → File Management, sau đó build và test.

---

## TASK 6 — CartItem

**👤 Quang Đại**

**File:**
- `cores/cart/CartItem.h`
- `cores/cart/CartItem.cpp`

**Cần làm:**
- Tạo `CartItem` gồm `Product* product` và `int quantity`.
- Constructor + getters.
- `increaseQuantity()` / `decreaseQuantity()`.
- `getSubtotal()`.

**Logic:**
- `Subtotal = calculateFinalPrice() × quantity`.
- Quantity không được âm.
- Không `delete Product`.

---

## TASK 7 — ShoppingCart

**👤 Tường Vy**

**File:**
- `cores/cart/ShoppingCart.h`
- `cores/cart/ShoppingCart.cpp`

**Cần làm:**
- Dùng `vector<CartItem> items`.
- `addProduct()`, `removeProduct()`.
- `displayCart()`, `calculateSubtotal()`.
- `isEmpty()`, `clear()`, `getItems()`.

**Logic:**
- Thêm cùng Product → cộng quantity, không tạo item trùng ID.
- Quantity không được vượt stock.
- `Subtotal = tổng subtotal của các CartItem`.

**Ví dụ:** `B001 × 2` + `B001 × 3` → `B001 × 5`.

---

## TASK 8 — OrderItem

**👤 Thư**

**File:**
- `cores/order/OrderItem.h`
- `cores/order/OrderItem.cpp`

**Cần làm:**
- Lưu `productId`, `productName`, `finalPrice`, `quantity`.
- Constructor + getters.
- `getSubtotal()`.
- `display()`.

**Logic:**
- `OrderItem` là snapshot sản phẩm tại thời điểm checkout.
- Luồng: `CartItem → Checkout → OrderItem`.
- Không dùng `Product*`.
- `Subtotal = finalPrice × quantity`.

---

## TASK 9 — Order

**👤 Minh Tiến**

**File:**
- `cores/order/Order.h`
- `cores/order/Order.cpp`

**Cần làm:**
- Lưu `orderId`, `orderDate`, `Customer`.
- Lưu `deliveryAddress`, `expectedDeliveryDate`.
- Lưu `vector<OrderItem> items`.
- Lưu `shippingFee`, `totalPayment`.
- Constructor + getters cần thiết.
- `calculateTotal()`.
- `displayOrder()`.

**Logic ngày:**
- `orderDate` tự lấy system date, user không nhập.
- Dùng `<chrono>` + `<ctime>`.
- Format `dd/mm/yyyy`.
- `expectedDeliveryDate = orderDate + 3 ngày`.

**Logic phí:**
- Subtotal < 500000 → Shipping = 30000.
- Subtotal >= 500000 → Shipping = 0.
- `Total = Subtotal + Shipping`.

---

## TASK 10 — FileManage

**👤 Hiếu Huy — Leader**

**File:**
- `manage/FileManage.h`
- `manage/FileManage.cpp`

**Data:**
- `data/products.txt`
- `data/OrderHistory.txt`

**Cần làm:**
- Đọc dữ liệu từ file.
- Ghi dữ liệu vào file.
- Append dữ liệu mà không làm mất dữ liệu cũ.
- Hỗ trợ lưu Order History.
- Test đọc `products.txt`.
- Test ghi/append `OrderHistory.txt`.

> `OrderHistory.txt` chỉ là file lưu lịch sử Order, không cần tạo class `OrderHistory`.

---

# 🧪 TEST

**Cart:**
- [ ] Add sản phẩm.
- [ ] Add trùng → cộng quantity.
- [ ] Không vượt stock.
- [ ] Remove sản phẩm.
- [ ] Tính subtotal.
- [ ] Test cart rỗng.

**Order:**
- [ ] OrderItem lưu đúng snapshot.
- [ ] Order date lấy system date.
- [ ] Expected delivery +3 ngày.
- [ ] Shipping đúng điều kiện.
- [ ] Total payment đúng.
- [ ] Display Order.

**File:**
- [ ] Đọc `products.txt`.
- [ ] Ghi file.
- [ ] Append `OrderHistory.txt`.
- [ ] Kiểm tra dữ liệu cũ không bị mất.

---

# ✅ QUY TRÌNH NỘP CODE

Mỗi thành viên:

`Code → Build → Test → Commit → Push branch → Pull Request`

> 🎯 Ưu tiên: **code chạy đúng → test pass → push**.
> Không tự thêm feature lớn ngoài task.