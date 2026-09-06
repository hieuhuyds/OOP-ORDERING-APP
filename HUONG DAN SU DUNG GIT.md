# 🚀 HƯỚNG DẪN CLONE CODE, TẠO NHÁNH VÀ PUSH LÊN GITHUB

---

### 📥 BƯỚC 1: Clone dự án về máy (Dành cho thành viên mới)

Mở Terminal và chạy lệnh để tải toàn bộ source code về máy:

```bash
# 1. Clone repository về máy
git clone https://github.com/hieuhuyds/OOP-ORDERING-APP.git

# 2. Di chuyển vào thư mục dự án
cd OOP-ORDERING-APP
```

---

### 🌿 BƯỚC 2: Tạo và chuyển sang nhánh riêng của bạn

> ⚠️ **Lưu ý:** Tuyệt đối không code trực tiếp trên nhánh `main`.

```bash
# 1. Đảm bảo đang ở nhánh main và có code mới nhất
git checkout main
git pull origin main

# 2. Tạo và chuyển ngay sang nhánh mới cho phần việc của bạn
git checkout -b feature/ten-chuc-nang-cua-ban
```

*(Ví dụ: **`git checkout -b feature/book-product`** hoặc **`git checkout -b feature/customer`**)*

---

### 💻 BƯỚC 3: Code và Lưu thay đổi (Commit)

Sau khi viết code và kiểm tra xong, thực hiện lưu các thay đổi:

```bash
# 1. Kiểm tra danh sách các file đã thay đổi
git status

# 2. Đưa toàn bộ file đã thay đổi vào khu vực chuẩn bị
git add .

# 3. Tạo commit với nội dung mô tả công việc đã làm
git commit -m "feat: mo ta cong viec da lam"
```

---

## 🚀 BƯỚC 4: Đẩy nhánh của bạn lên GitHub

```bash
# Đẩy nhánh của bạn lên GitHub (lần đầu tiên)
git push -u origin feature/ten-chuc-nang-cua-ban

# Những lần push tiếp theo trên cùng nhánh này chỉ cần gõ:
git push
```

Sau khi push thành công:

1. Vào GitHub → **Compare & pull request**.
2. Chọn `base: main` và `compare: feature/ten-chuc-nang-cua-ban`.
3. Tạo **Pull Request**.
4. **Không tự merge** → chờ Leader kiểm tra.
5. Leader kiểm tra code, Build và Test:
   - ✅ Đạt → Leader **Merge Pull Request** vào `main`.
   - ❌ Chưa đạt → Member sửa code → `commit` → `push` → Leader kiểm tra lại.

### 🔄 BƯỚC 5: Cập nhật code mới từ `main` (Khi có bạn khác vừa cập nhật)

Khi nhánh `main` có code mới và bạn muốn cập nhật vào nhánh đang làm của mình:

```bash
# 1. Chuyển về nhánh main và lấy code mới nhất
git checkout main
git pull origin main

# 2. Quay lại nhánh của bạn và gộp code mới vào
git checkout feature/ten-chuc-nang-cua-ban
git merge main
```