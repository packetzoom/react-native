import { NativeModules } from 'react-native';

const Packetzoom = NativeModules.RNPacketzoom;

export default {
  getVersion: function () {
    return Packetzoom.version;
  },
  
  init: function (appId, apiKey) {
      Packetzoom.init(appId, apiKey);
  }
}
