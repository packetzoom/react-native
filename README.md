# react-native-packetzoom [![npm version](https://img.shields.io/npm/v/react-native-packetzoom.svg?style=flat)](https://www.npmjs.com/package/react-native-packetzoom)

React Native PacketZoom SDK for iOS + Android

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

## iOS

<blockquote class="imgur-embed-pub" lang="en" data-id="z71C8Nh"><a href="//imgur.com/z71C8Nh"></a></blockquote><script async src="//s.imgur.com/min/embed.js" charset="utf-8"></script>

## Javascript
```js

import Packetzoom from 'react-native-packetzoom'

Packetzoom.init('app-id', 'api-key')
```
