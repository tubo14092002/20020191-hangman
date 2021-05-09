# 20020191-hangman
Tựa game hangman cùng đồ họa và âm thanh kinh dị với cách chơi đoán chữ đơn giản bằng C++ và SDL
main.cpp hàm main, chứa cơ chế chơi chính của game
Base Object : chứa các thông tin cơ , tiền đề cho các hàm tiếp theo;
commonfunc : chứa các hàm load ảnh, hàm tạo menu, hàm clean up;
Text Object : load phông chữ và load chữ lên game;
Hangman : chứa các thông tin nhập vào từ bàn phím .ex: nhấn a -> nhận vào a để kiểm tra ở hàm main;
