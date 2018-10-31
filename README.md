# Mega Drive USB Link [![CircleCI](https://circleci.com/gh/rhargreaves/mega-drive-usb-link.svg?style=svg)](https://circleci.com/gh/rhargreaves/mega-drive-usb-link)
Proving that you can send bits over USB to the Everdrive cart

## Getting Started

This code has two purposes as defined by this code in [src/main.c](src/main.c):

```c
#define MODE_PING 0
#define MODE_RATE_TEST 1

static u16 default_mode = MODE_PING;
```

`PING` is a method of calculating round-trip latency from a PC to a Mega Drive by having the PC send a character to the Mega Drive, which upon receipt will immediately respond with a character back. The [many_ping](many_ping) script can be used to find the average time to send & receive ping requests & responses.

`RATE_TEST` is a method of calculating throughput in bytes per second, by simply counting bytes received over the USB. Piping `/dev/zero` into the USB serial device works well! 

### Results

The following metrics were calculated using the tooling described above:

* Maximum throughput/rate = **50,000 bytes/sec**.
* Mean latency = **~2.1 ms**.

## Compiling ROM

Docker:

```sh
./docker-make all
```

Linux (requires `cmake`):

```sh
make all
```

## Running Unit Tests

Unit tests built with `cmocka` and are compiled to x86. Mega Drive interfaces are mocked out.

Docker:

```sh
./docker-make test
```

Linux:

```sh
make test
```


## References

* [extended_ssf-v2](http://krikzz.com/pub/support/mega-everdrive/x3x5x7/dev/extended_ssf-v2.txt)
