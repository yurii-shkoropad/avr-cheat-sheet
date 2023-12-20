# Bitwise operations

## Bit mask
| Bit number | Binary     | HEX  | Decimal |
| ---------- | ---------- | ---- | ------- |
| 0          | Ob00000001 | 0x01 | 1       |
| 1          | Ob00000010 | 0x02 | 2       |
| 2          | Ob00000100 | 0x04 | 4       |
| 3          | Ob00001000 | 0x08 | 8       |
| 4          | Ob00010000 | 0x10 | 16      |
| 5          | Ob00100000 | 0x20 | 32      |
| 6          | Ob01000000 | 0x40 | 64      |
| 7          | Ob10000000 | 0x80 | 128     |

## Read register bit
`btn_3_state = PORTB & 0x04`
`btn_3_state = PORTB & Ob00000100`
`btn_3_state = PORTB & 4`

## Set register bit

### Set 1

`port_d = port_d | 0x04`
`port_d = port_d | Ob00000100`
`port_d = port_d | 4`

`port_d |= 0x04`
`port_d |= Ob00000100`
`port_d |= 4`

#### Set multiply
`port_d |= 0x04 | 0x08 | 0x10`
`port_d |= 4 | 8 | 16`

### Set 0
`port_d = port_d | 0x04`
`port_d = port_d | Ob00000100`
`port_d = port_d | 4`