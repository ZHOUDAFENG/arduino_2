# -*- coding: utf-8 -*-
from wxpy import *
import sys


bot = Bot(cache_path=True)
non_bmp_map = dict.fromkeys(range(0x10000, sys.maxunicode + 1), 0xfffd)


# 机器人账号自身
bot.file_helper.send("实验开始")


import paho.mqtt.client as mqtt

MQTTHOST = "172.16.145.3"
MQTTPORT = 1883
mqttClient = mqtt.Client()


# 连接MQTT服务器
def on_mqtt_connect():
    mqttClient.connect(MQTTHOST, MQTTPORT, 60)
    mqttClient.loop_start()


# publish 消息
def on_publish(topic, payload, qos):
    mqttClient.publish(topic, payload, qos)

# 消息处理函数
def on_message_come(lient, userdata, msg):
    ii = str(msg.payload.decode("utf-8")).split(",")
    try:
        bot.file_helper.send( '学号:（'+ii[0]+"）已经完成,   实验名称:  (实验"+ii[1]+"）,  \
实验时间:  ("+ii[2]+"分钟) , 实验次数：("+ii[3]+")  , 实验成绩:("+ii[4]+") 。")
    except BaseException as e:
        print(e)

# subscribe 消息
def on_subscribe():
    for i in ["zhou/001say","zhou/002say","zhou/003say"]:
        mqttClient.subscribe(i, 1)
    mqttClient.on_message = on_message_come 


def main():
    on_mqtt_connect()
    on_publish("/wxpy", "Hello !", 1)
    on_subscribe()
    while True:
        pass



if __name__ == '__main__':
    main()

    
