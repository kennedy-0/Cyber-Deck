import time
import psutil
import board
import busio
from PIL import Image, ImageDraw, ImageFont
import adafruit_ssd1306

WIDTH = 128
HEIGTH = 64

i2c = busio.I2C(board.SCL, board.SDA)
oled = adafruit_ssd1306.SSD1306_I2C(WIDTH, HEIGTH, i2c, addr=0x3C)

image = Image.new("1", (WIDTH, HEIGTH))
draw = ImageDraw.Draw(image)
font = ImageFont.load_default()

def sla():
        info ={}
        with open("/proc/meminfo", "r") as arquivo:
                for linha in arquivo:
                        chave, valor = linha.split(":")
                        info[chave] = int(valor.strip().split()[0])
        return info
def nb():
        with open("/sys/class/thermal/thermal_zone0/temp", "r") as arquivo:
                temp = int(arquivo.read()) / 1000
        return temp

while True:
        temp = nb()
        mem = sla()
        total = mem["MemTotal"]
        cache = mem["Cached"]

        cache = int((cache * 100) /total)
        cpu = psutil.cpu_percent()
        ram = psutil.virtual_memory().percent
        draw.rectangle((0, 0, WIDTH, HEIGTH), fill=0)

        draw.text((0, 0), "Cyber Wanderer" , font=font, fill=255)
        draw.text((0,14), f"CPU: {cpu:.0f}%", font=font, fill=255)
        draw.text((0,24), f"RAM: {ram:.0f}%", font=font, fill=255)
        draw.text((0,34), f"CACHE: {cache}%", font=font, fill=255)
        draw.text((0,44), f"TEMP: {temp:.1f}C", font=font, fill=255)
        oled.image(image)
        oled.show()
        time.sleep(0.2)
