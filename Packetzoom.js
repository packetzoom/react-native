import { NativeModules } from 'react-native';

const Packetzoom = NativeModules.RNPacketzoom;

module.exports = {
  getConstant: function () {
    return Packetzoom.hello;
  },
};
