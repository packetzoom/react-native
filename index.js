import { NativeModules } from 'react-native';

var pz = NativeModules.RNPacketzoom

export default {
    getVersion: function() {
        return pz.version
    },
    
    init: function(appid, apikey) {
        pz.init(appid, apikey)
    }
}
