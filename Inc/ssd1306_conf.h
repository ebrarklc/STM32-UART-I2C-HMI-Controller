#ifndef __SSD1306_CONF_H__
#define __SSD1306_CONF_H__

// 1. İşlemci Ailesi
#define STM32F4

// 2. Haberleşme Tipi ve Portu
#define SSD1306_USE_I2C
#define SSD1306_I2C_PORT        hi2c1

// 3. OLED Boyutları ve Adresi
#define SSD1306_WIDTH           128
#define SSD1306_HEIGHT          64
#define SSD1306_I2C_ADDR        0x78

// 4. KULLANILACAK FONTLARI AKTİF ETME (Şalteri Kaldırdığımız Yer)
#define SSD1306_INCLUDE_FONT_6x8
#define SSD1306_INCLUDE_FONT_7x10
#define SSD1306_INCLUDE_FONT_11x18
#define SSD1306_INCLUDE_FONT_16x26

#endif /* __SSD1306_CONF_H__ */
