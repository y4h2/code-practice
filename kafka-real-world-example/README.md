# kafka-real-world-example
list runnable kafka examples

# Examples in the hub
## kafka with java

## kafka with python

## kafka integration with storm
kafka-storm-wordcount



# Configuration (standalone mode)
## config zookeeper

```sh

```


## config kafka
if you use vm, please make sure the memory size of VM. (in the VM, you can check with command ```top```)<br>
Since kafka broker (namely kafka server) default allocate 1G for jvm to start, if your machine's memory is not enough, you should change file ```kafka-server-start.sh``` in bin folder.

In standalone mode, there is no need to configure anything. Once you dowload and unzip kafka, you can use the shell in its bin/ folder directly.
The version of this project:
```sh
wget http://apache.mirror.gtcomm.net/kafka/0.8.2.1/kafka_2.9.1-0.8.2.1.tgz
tar -xvzf kafka_2.9.1-0.8.2.1.tgz
```


# Commands
suggest use screen split tools (eg. tmux)
```sh
# start a kafka server
> ./bin/kafka-server-start.sh config/server.properties
# create a topic
> ./bin/kafka-topics.sh --create --zookeeper localhost:2181 --replication-factor 1 --partitions 1 --topic test
# list topics
> ./bin/kafka-topics.sh --list --zookeeper localhost:2181
# get more details of a specific topic
>  ./bin/kafka-topics.sh --describe --ZooKeeper localhost:2181 --topic test
# start a producer
> ./bin/kafka-console-producer.sh --broker-list localhost:9092 --topic test
# start a consumer
> ./bin/kafka-console-consumer.sh --zookeeper localhost:2181 --topic first --from-beginning
```

