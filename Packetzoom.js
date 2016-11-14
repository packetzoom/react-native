import { NativeModules } from 'react-native';

const Packetzoom = NativeModules.RNPacketzoom;

module.exports = {
  getVersion: function () {
    return Packetzoom.version;
  },
  
  init: function (appId, apiKey) {
      Packetzoom.init(appId, apiKey);
  }
};
