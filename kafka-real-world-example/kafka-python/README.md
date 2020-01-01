Kafka with Python
----

# install
```sh
sudo pip install kafka-python
```



# Producer
```python
>>> from kafka import KafkaClient, SimpleProducer, SimpleConsumer
>>> kafka = KafkaClient("localhost:9092")
>>> producer = SimpleProducer(kafka)
>>> producer.send_messages("first", "hello python!")
[ProduceResponsePayload(topic=u'first', partition=0, error=0, offset=0)]
>>> producer.send_messages("first", "hello again!", "nice to meet you")
[ProduceResponsePayload(topic=u'first', partition=0, error=0, offset=1)]
>>> producer = SimpleProducer(kafka, async=True)
```

# Consumer
>>> from kafka import KafkaClient, SimpleProducer, SimpleConsumer
>>> kafka = KafkaClient("localhost:9092")
>>> consumer = SimpleConsumer(kafka, "python", "first")
>>> for msg in consumer:
>>> 	print msg

# exit
>>> kafka.close()
>>> exit()

# Official Example
https://github.com/dpkp/kafka-python/blob/master/example.py