#  STM32 HMI & Uzaktan Denetim Sistemi (UART / I2C)

Bu repo, gömülü sistem mimarilerinde yaygın olarak kullanılan UART ve I2C kablolu haberleşme protokollerinin donanımsal ve yazılımsal çalışma prensiplerini içerir[cite: 2]. Proje, bir bilgisayar (Master/PC) ile STM32 (Slave) arasında çift yönlü bir komut-yanıt (Command-Response) mimarisi kurarak uzaktan denetim sistemi tasarlamayı amaçlamaktadır[cite: 2].

## 🚀 Öne Çıkan Özellikler (Highlights)

*   **Non-Blocking UART Kesme Mimarisi:** Dış birimlerden gelen veriler, işlemci döngüsünü (CPU Cycle) bloklamadan UART Kesmesi (Interrupt) mekanizması ile asenkron şekilde işlenir[cite: 2].
*   **I2C OLED Kontrolü:** I2C protokolü altyapısı kullanılarak SSD1306 kontrolcüsüne sahip OLED ekran modülü sürülmektedir[cite: 2]. Sistem durum verileri bu ekran üzerinden gerçek zamanlı olarak görselleştirilir[cite: 2].
*   **Python HMI Arayüzü:** Bilgisayar ile entegrasyonu sağlamak amacıyla, seri port üzerinden haberleşebilen Python tabanlı bir Grafiksel Kullanıcı Arayüzü (GUI) geliştirilmiştir[cite: 2].
*   **Açık Kaynak Kütüphane Entegrasyonu:** Projede OLED ekranı sürmek için açık kaynak dünyasında yaygın olarak kullanılan `afiskon/stm32-ssd1306` kütüphanesi manuel olarak sisteme entegre edilmiştir[cite: 2].

## 🛠️ Donanım ve Pin Yapılandırması

Sistemdeki dış birimlerin STM32F407 üzerindeki pin karşılıkları ve konfigürasyon modları aşağıda listelenmiştir:

*   **Harici UART - TX (`PA10`):** Bilgisayara durum mesajı (String) iletmek için kullanılır[cite: 2].
*   **Harici UART - RX (`PA9`):** Bilgisayardan gelen tek baytlık komutları (Interrupt ile) alır[cite: 2].
*   **OLED Ekran - SCL (`PB6`):** OLED ekran iletişim senkronizasyonunu sağlar[cite: 2].
*   **OLED Ekran - SDA (`PB7`):** OLED ekrana komut ve piksel verilerini aktarır[cite: 2].
*   **Röle Modülü (`PC7`):** Gelen 'R' komutu ile yüksek voltajlı yükleri anahtarlar[cite: 2].
*   **Durum LED'i (`PE0`):** Gelen 'L' komutu ile görsel geri bildirim sağlar[cite: 2].
*   **Buzzer (`PA8`):** Gelen 'B' komutu ile işitsel uyarı oluşturur[cite: 2].

## 📂 Yazılım Mimarisi ve Çalışma Prensibi

1.  **Haberleşme Ağı:** Cihaz çalıştırıldığında STM32, I2C hattı üzerinden OLED ekranı başlatır ve UART kesmesini aktifleştirerek dinleme moduna geçer.
2.  **HMI Komutları:** Python arayüzündeki butonlara tıklandığında, seri port üzerinden 'R', 'L' veya 'B' karakterleri byte dizisine çevrilerek (encode) gönderilir[cite: 2].
3.  **Kesme Servis Rutini (ISR):** Gelen komut, donanımsal olarak kesme (Interrupt) oluşturur ve `HAL_UART_RxCpltCallback` fonksiyonunu tetikler.
4.  **Eylem ve Geri Bildirim:** Gelen komuta göre ilgili donanım (Röle, LED veya Buzzer) çalıştırılır (Toggle), OLED ekrana yeni durum yazdırılır ve bilgisayara başarı mesajı (ACK) geri gönderilir.

## 💻 Nasıl Çalıştırılır?

1.  **STM32 Tarafı:** Repoda bulunan C kodlarını `STM32CubeIDE` ile açın. Kodu derleyip (`Build`) hedef karta yükleyin.
2.  **Bağlantı:** Deney setini bilgisayarınıza bağlayın.
3.  **Python Bağımlılıkları:** Bilgisayarınızda terminal (CMD) üzerinden şu komut çalıştırılarak seri haberleşme modülü yüklenmelidir[cite: 2]:
    ```bash
    pip install pyserial
    ```
4.  **Arayüzü Başlatma:** `arayuz.py` dosyasını çalıştırın (Kod içerisindeki `PORT_NUMARASI` değişkenini kendi Aygıt Yöneticinizdeki COM portuna göre güncellemeyi unutmayın)[cite: 2]. Açılan HMI paneli üzerinden sistemi uzaktan yönetmeye başlayabilirsiniz!

5.  <img width="1024" height="683" alt="image" src="https://github.com/user-attachments/assets/4bd14d72-c6fe-4097-82ad-0326934f9f01" />
