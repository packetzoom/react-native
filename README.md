# react-native-packetzoom [![npm version](https://img.shields.io/npm/v/react-native-packetzoom.svg?style=flat)](https://www.npmjs.com/package/react-native-packetzoom)

# Redefining Networking For React Native

React Native PacketZoom SDK for iOS + Android

![](http://i.imgur.com/GPEgdkT.png)


# Intro

At __PacketZoom__ we designed from the ground up modern UDP-based network protocol with mobile apps in mind. This enables faster downloads, reduced latency, efficient and reliable data transfers between your app and the cloud. In addition to speed, one of the advantages of PacketZoom is that it handles seamless transition between networks without interrupting ongoing sessions. This is a unique advantage of the PacketZoom protocol over HTTP/TCP stack is already in production use with many mobile apps. 

Today we're redefining how networking works for React Native apps, empowering them with __PacketZoom__ sdk and our [worldclass cluster of servers](http://status.packetzoom.com).

# How

Following diagram shows overhead of establishing TLS/SSL connection over TCP socket on relatively fast wifi. The advantage of __PacketZoom__ is that we have zero roundtrips to establish connection with our EDGE servers, small amount of data like API call is fetched from PZ server within single roundtrip as oppose to traditional multi-roundtrip TLS/SSL over TCP flow
 
[![unnamed.png](https://s16.postimg.org/gx0dgrgut/unnamed.png)](https://postimg.org/image/ajbadibyp/)

Now consider more complex real world scenario. To give you some perspective of how much time it takes make an API call to your endpoint in AWS US East (N. Virginia) location from customer located in India on mobile network here some raw numbers


| Tables         | 3g            | 4g        |
| -------------- |--------------:| ---------:|
| Control plane  | 200–2,500 ms  | 50–100 ms |
| DNS lookup     | 200 ms        |    100 ms |
| TCP handshake  | 200 ms        |    100 ms |
| TLS handshake  | 200 - 4000 ms |100 - 200 ms |
| HTTP request   | 200 ms        |    100 ms |
| __Total latency overhead__  | 200–3500 ms   | 100–600 ms|

Thats a whole lot of time user have to wait for completing just single API call, she might already switched to another app
or decided to check Facebook feed while waiting for your app to respond.

Where [Control plane](https://en.wikipedia.org/wiki/Control_plane) latency: Fixed, one-time latency cost incurred for [RRC](https://en.wikipedia.org/wiki/Radio_Resource_Control) negotiation and state transitions: <100 ms for idle to active, and <50 ms for dormant to active. 

To understand how just few seconds can affect your customers experience here is great excerpt from Ilya Grigorik book [High Performance Browser Networking](http://chimera.labs.oreilly.com/books/1230000000545/index.html)

*We are not accustomed to measuring our everyday encounters in milliseconds, but studies have shown that most of us will reliably report perceptible "lag" once a delay of over 100–200 milliseconds is introduced into the system. Once the 300 millisecond delay threshold is exceeded, the interaction is often reported as "sluggish," and at the 1,000 milliseconds (1 second) barrier, many users have already performed a mental context switch while waiting for the response*

Not convinced yet ?

There is a whole chapter (7th) dedicated to mobile networks. The book states that the problem with high performance is almost always tied to latency, we usually have plenty of bandwidth but the protocols gets in the way. Be it [TCP slow start](https://en.wikipedia.org/wiki/TCP_congestion-avoidance_algorithm#Slow_start), the [Radio Resource Controller](https://en.wikipedia.org/wiki/Radio_Resource_Control) (RRC) or suboptimal configurations. If you are experiencing poor latency only in mobile networks it's the way they are designed.

Besides eliminating legacy handshakes and DNS lookups PZ stack uses custom congestion control algorithms tailored for specific network types which makes data delivery faster than TCP with it's slow start, Tahoe, Reno, CuBiC or whatever else one-size-fits-all approach.

PacketZoom treats the actual mobile device as the destination for data packets, compared to legacy protocols that use only the device's IP address.

Treating the device itself as a unique destination allows PacketZoom to easily handle the intermittent nature of mobile connections in an intelligent, fault-tolerant way. So as your device moves across networks, any ongoing transfers can continue seamlessly something that is simply impossible with old-fashioned legacy protocols.

Here is another piece by PacketZoom CTO/co-founder Chetan Ahuja on [faster approach to DNS lookups]
(http://www.infoworld.com/article/3133104/mobile-technology/why-your-mobile-connection-is-so-slow.html) which used in our stack.

# Installation

First, download the library from npm:

```
npm install react-native-packetzoom@latest --save
```

Then you must install the native dependencies: You can use `rnpm` (now part of `react-native` core) to
add native dependencies automatically then continue the directions below depending on your target OS.

   `$ react-native link`
   
React Native versions from 0.30 and above should work out of the box, we cannot guarantee that earlier than 0.30
will have smooth integration experience, it may require additional manual steps like `rnpm` for example.

## Javascript
```js

import Packetzoom from 'react-native-packetzoom'

Packetzoom.init('packetzoom-app-id', 'packetzoom-api-key')
```

You can sign up for free __PacketZoom__ account here: https://packetzoom.com/developers.html to get your credentials.

The XMLHttpRequest API is built in to React Native. This means that you can use third party libraries such as [Frisbee](https://github.com/crocodilejs/frisbee), [Fetch](https://developer.mozilla.org/en-US/docs/Web/API/Fetch_API) or [Axios](https://github.com/mzabriskie/axios) that depend on it. Ultimately XMLHttpRequest API is implemented using native [NSURLSession API](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/URLLoadingSystem/Articles/UsingNSURLSession.html#//apple_ref/doc/uid/TP40013509-SW1) on iOS side and [OkHttp3](https://github.com/square/okhttp) on Android
where PacketZoom native sdk would eventually intercept them.

From now on all your [Fetch API](https://developer.mozilla.org/en-US/docs/Web/API/Fetch_API),
[Axios](https://github.com/mzabriskie/axios) or [Apisauce](https://github.com/skellock/apisauce) requests will be accelerated
by __PacketZoom__. You can access all NewRelic'sque kind of [network analytics](https://packetzoom.com/blog/introducing-http-optimizer-and-analytics-service.html) data on web dashboard when you login under your account.

## iOS

Drag PZSpeed.Framework from RNPacketZoom.xcodeproj to your app frameworks folder like shown bellow:

![](http://i.imgur.com/z71C8Nh.png)


Make sure you linking against it in Build Phases -> Link Binary with Libraries section

![](http://i.imgur.com/e6ftLfX.png)

Also make sure that the following frameworks and libraries are part of your project: 

- CoreLocation.framework
- SystemConfiguration.framework
- CoreTelephony.framework
- Foundation.framework
- libz.tbd
- libc++.tbd

## Android

No additional changes required for Android


## Who uses PacketZoom

![](https://packetzoom.com/images/customers/glu-logo.svg)
![](https://s16.postimg.org/kgmyiwtd1/houzify.png)
![](https://s11.postimg.org/tgpt2cw7n/News_Republic.png)
</br>
![](https://s13.postimg.org/y8h5jaxyb/Screen_Shot_2016_11_20_at_10_10_41_PM.png)
![](https://s21.postimg.org/b0kis6gav/wooplr.png)
</br>
![](https://s21.postimg.org/qy00uctw7/goat.png)
![](https://lh4.ggpht.com/Fvhs0PlDSFktdjZlNyl8QVVCVOSxPI3XtlShzFpaYwx7Bv-vyK_OZnIuVGfT8fXtdP8=w300)

[Join The Rebellion](https://packetzoom.com/developers.html) and experience request speedups and uninterrupted network connections across all mobile and wifi networks
