# 🧠 C++ ile Sıfırdan Yapay Sinir Ağı (Neural Network from Scratch)

Bu proje, hiçbir harici matematik veya yapay zeka kütüphanesi kullanılmadan, tamamen C++ standart kütüphanesi ile sıfırdan yazılmış bir İleri Beslemeli Yapay Sinir Ağı (Feedforward Neural Network) uygulamasıdır. 

Projenin temel amacı, makine öğrenmesinin arka planında çalışan lineer cebir (matris operasyonları) ve kalkülüs (türev ve zincir kuralı) temellerini Nesne Yönelimli Programlama (OOP) prensipleriyle koda dökmektir.

## 🚀 Özellikler

* **Bağımsız Mimari:** Dışa bağımlılık yoktur (No external dependencies).
* **Özelleştirilmiş Matris Sınıfı:** Dinamik boyutlandırma, matris çarpımı, transpoze alma ve Hadamard çarpımı gibi işlemleri yöneten özel `Matrix` modülü.
* **İleri Yayılım (Forward Propagation):** Girdi verilerinin katmanlar arası ağırlık ve bias değerleriyle hesaplanarak Sigmoid aktivasyon fonksiyonundan geçirilmesi.
* **Geri Yayılım (Backpropagation):** Ağın yaptığı hatayı minimuma indirmek için Gradyan İnişi (Gradient Descent) optimizasyonu ve ağırlık güncellemeleri.
* **İnteraktif Test Ortamı:** Kullanıcıdan anlık girdiler alarak ağın eğitilmiş tahminlerini sunan konsol arayüzü.

## 🛠️ Kullanılan Teknolojiler

* C++ (Standart Kütüphane)
* Nesne Yönelimli Programlama (Modüler Header ve Kaynak dosyaları)

## 🧮 Matematiksel Altyapı

Ağın öğrenme süreci aşağıdaki temel formüllerin C++ implementasyonuna dayanır:
* **Aktivasyon (Sigmoid):** `f(x) = 1 / (1 + e^(-x))`
* **Ağırlık Güncellemesi (Delta W):** `ΔW = α * (Error ∘ f'(Output)) * Input^T`

## 👨‍💻 Geliştirici
**Arhan Topal** İstanbul Teknik Üniversitesi (İTÜ) - Matematik Mühendisliği