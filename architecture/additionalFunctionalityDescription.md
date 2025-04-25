- # Additional Functionality Documentation

---

## **New Game Mode: Fixed Attacks**
### **Overview**
- **Mode Name**: `fixed`
- **Purpose**: Provides deterministic damage calculations, removing reliance on random chance. Ideal for strategic planning.

### **Mechanics**
- **Damage Formula**: maxAttackingCharacteristics-1 * 10.4
- Example: A Mage with a max attack characteristic of 7 deals `(7-1) * 10.4 = 62.4` damage per attack.
- **Key Changes**:
- No random critical hits or variable damage rolls.
- Abilities relying on RNG (e.g., Assassin’s "assassinate") are disabled.

### **Strategy Tips**
- Prioritize roles with **high max attack stats** (e.g., Warrior, Mage).
- Use shields and revives to maintain consistent damage output.

---

## **Mage: Accumulating Shield**
### **Ability: Shield**
- **Mechanics**:
- Generates a random shield value (1–20) and adds it to the **team-wide shield pool**.
- At the end of each turn, alive team members heal by `teamShield / 2`.
- Example: Two shields (15 + 8) = 23 total shield → each member heals `23 / 2 = 11.5` HP.
- **Fixed Mode Interaction**:
- Shield generation is still random, but distribution is deterministic.

---

## **Necromancer: Reliable Revive**
### **Ability: Arise**
- **Mechanics**:
- Revives **dead allies** (health ≤ 0) with **50 HP**.
- No resource cost (e.g., potions).
- **Fixed Mode Interaction**:
- Revived allies benefit from predictable damage calculations.

---

## **Balance & Synergy**
### **Mage + Fixed Mode**
- Use shields early to offset predictable enemy damage.
- Pair with a Warrior for high fixed damage.

### **Necromancer + Tank**
- Let a tank die intentionally, then revive them to stall enemies.

---

## **Version & Updated Files**
- **Version**: 1.2.0
- **Modified Files**:
- `Mage.cpp` (shield logic)
- `Necromancer.cpp` (arise logic)
- `Role.cpp` (`basicFixedAttack` method)
- `main.cpp` (mode selection and team shield distribution)

---

**Example Team for Fixed Mode**
1. **Warrior**: Deal 62.4 damage per turn.
2. **Mage**: Build shields for survivability.
3. **Necromancer**: Revive fallen allies to sustain pressure.  