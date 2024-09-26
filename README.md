# The Cnake 🐍

The Cnake adalah implementasi sederhana dari permainan klasik **Snake** yang dimainkan di dalam terminal. Proyek ini ditulis dalam bahasa C menggunakan beberapa library seperti `conio.h` untuk mendeteksi input dari keyboard, dan `windows.h` untuk fungsi `Sleep()`.

## Cara Bermain 🎮

- Permainan dimulai dengan ular kecil yang bergerak di dalam area bermain.
- Anda harus mengendalikan ular dengan **W**, **A**, **S**, **D** untuk memakan apel (*ditandai dengan `*`*) dan memperpanjang ekor ular.
- Setiap kali ular memakan apel, skornya akan meningkat 10 poin, dan ekornya akan bertambah panjang.
- Permainan berakhir ketika ular menabrak ekornya sendiri.

## Tombol Pengendali 🕹️

- **W**: Bergerak ke atas
- **A**: Bergerak ke kiri
- **S**: Bergerak ke bawah
- **D**: Bergerak ke kanan

## Fitur Permainan 🔥

- **Papan skor**: Skor Anda akan ditampilkan di bagian bawah layar saat permainan berlangsung.
- **Looping dinding**: Ular tidak akan mati saat menabrak dinding, tetapi akan muncul kembali di sisi sebaliknya.
- **Game over**: Jika ular menabrak ekornya sendiri, permainan akan berakhir dan skor akhir akan ditampilkan.

## Cara Menjalankan 🛠️

1. Pastikan Anda telah menginstal **compiler C** seperti GCC atau Dev-C++.
2. Clone atau unduh repository ini.
3. Buka terminal atau command prompt di folder proyek.
4. Kompilasi kode menggunakan perintah berikut:

   ```bash
   gcc -o cnake cnake.c
