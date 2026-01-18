# 🏦 EKICI BANK - ATM & Banking System Simulation (English)

A comprehensive banking and investment management system simulation developed using C++.

## 🚀 Key Features

* **Secure Authentication:** Registration with unique ID check and password protection.
* **Account Operations:** Automatic 18-digit IBAN generation and balance management.
* **Investment Module:** Buy/Sell Gold, USD, and EUR based on custom exchange rates.
* **Money Transfer:** Send money to other users via IBAN with transaction cost calculation.
* **Billing System:** Add, view, and pay bills using the `std::map` data structure.

## 🛠 Technical Highlights

* **Inheritance:** `Users` class inherits from `ExchangeInvest` and `TotalMoneyCalculate`.
* **Data Storage:** Dynamic user management with `std::vector<Users*>`.
* **Input Validation:** Robust error handling with `try-catch` for IBAN and menu selections.

---
Developed by **Mehmet Efe Ekici**

# 🏦 EKICI BANK - ATM & Banking System Simulation

Bu proje, C++ programlama dili kullanılarak geliştirilmiş kapsamlı bir banka ve yatırım yönetim sistemi simülasyonudur. Proje kapsamında nesne yönelimli programlama (OOP), hata ayıklama (exception handling) ve dinamik veri yapıları etkin bir şekilde kullanılmıştır.

## 🚀 Özellikler

- **Kullanıcı Kayıt & Giriş Sistemi:** Benzersiz TC Kimlik Numarası kontrolü ve şifreli giriş.
- **Hesap Yönetimi:** Kullanıcıya özel otomatik IBAN üretimi (18 haneli) ve bakiye takibi.
- **Yatırım Sayfası:** Canlı altın, dolar ve euro kurları üzerinden alım-satım işlemleri.
- **Para Transferi:** IBAN üzerinden kullanıcılar arası anlık para gönderimi ve masraf hesaplama.
- **Fatura Sistemi:** Map yapısı kullanılarak fatura ekleme, görüntüleme ve bakiye ile ödeme.
- **Güvenlik:** Mevcut şifre doğrulamalı şifre değiştirme menüsü.

## 🛠 Kullanılan Teknolojiler ve Yapılar

* **Dil:** C++
* **OOP Prensipleri:** Kalıtım (Inheritance), Sınıflar (Classes), Fonksiyon Aşırı Yükleme (Overloading).
* **STL Yapıları:** `std::vector` (Kullanıcı listesi), `std::map` (Fatura veritabanı).
* **Hata Yönetimi:** `try-catch` blokları ile giriş kontrolü.
* **Rastgelelik:** `std::random_device` ve `mt19937` ile güvenli IBAN üretimi.

## 📖 Kurulum ve Çalıştırma

1.  Bilgisayarınızda bir C++ derleyicisinin (GCC, MSVC vb.) kurulu olduğundan emin olun.
2.  `main.cpp` dosyasını indirin.
3.  Terminal veya komut satırını açarak dosyayı derleyin:
    ```bash
    g++ main.cpp -o EkiciBank
    ```
4.  Uygulamayı çalıştırın:
    ```bash
    ./EkiciBank
    ```

## 📝 Geliştirici Notları

* Program Windows işletim sistemi odaklı `system("cls")` ve `system("timeout")` komutlarını kullanmaktadır.
