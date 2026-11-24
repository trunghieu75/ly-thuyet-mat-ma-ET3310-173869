# Cài đặt AES-128 bằng C

Chương trình mã hóa và giải mã một khối 128 bit, sử dụng khóa 128 bit và in trạng thái trung gian.

## Dữ liệu kiểm thử


- Bản rõ: `0123456789ABCDEFFEDCBA9876543210`
- Khóa: `0F1571C947D9E8590CB7ADD6AF7F6798`
- Bản mã mong đợi: `FF0B844A0853BF7C6934AB4364148FB9`
- Khóa vòng 1: `DC9037B09B49DFE997FE723F388115A7`

Chương trình kiểm tra khóa vòng 1, kết quả mã hóa và dữ liệu sau giải mã.

