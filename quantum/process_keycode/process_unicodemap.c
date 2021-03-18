/* Copyright 2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "process_unicodemap.h"

#define LAST(k,n) ((k) & ((1<<(n))-1))
#define MID(k,m,n) LAST((k)>>(m),((n)-(m)))

// __attribute__((weak)) uint16_t unicodemap_index(uint64_t keycode) {
//     if (keycode >= QK_UNICODEMAP_PAIR) {
//         // Keycode is a pair: extract index based on Shift / Caps Lock state
//         uint16_t index = keycode - QK_UNICODEMAP_PAIR;

//         bool shift = unicode_saved_mods & MOD_MASK_SHIFT;
//         bool caps  = IS_HOST_LED_ON(USB_LED_CAPS_LOCK);
//         if (shift ^ caps) {
//             index >>= 7;
//         }

//         return index & 0x7F;
//     } else {
//         // Keycode is a regular index
//         return keycode - QK_UNICODEMAP;
//     }
// }

__attribute__((weak)) uint16_t unicodemap_index(uint64_t keycode) {
    
    bool shift = MOD_MASK_SHIFT;
    bool caps  = IS_HOST_LED_ON(USB_LED_CAPS_LOCK);
    bool shift_all = shift ^ caps;
    bool altgr = MOD_MASK_AG;

    if(shift_all){
         if(altgr){
            // return altgr + shift, the most significant number
            return pgm_read_dword(unicode_map_altgrshift + MID(keycode,48,64));
        } 
        else{
            // return shift, the third most significant
            return pgm_read_dword(unicode_map_shift + MID(keycode,16,32));
        }    
    }
    else{
        if(altgr){
            // return altgr, the second most significant
            return pgm_read_dword(unicode_map_altgr + MID(keycode,32,48));
        }
        else{
            // return normal, the least significant
            return pgm_read_dword(unicode_map + MID(keycode,0,16));
        }
    }

}



bool process_unicodemap(uint16_t keycode, keyrecord_t *record) {
    if (keycode >= QK_UNICODEMAP && keycode <= QK_UNICODEMAP_Q_MAX && record->event.pressed) {
        uint32_t code_point = unicodemap_index(keycode);// pgm_read_dword(unicode_map + unicodemap_index(keycode));
        register_unicode(code_point);
    }
    return true;
}
