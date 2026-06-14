# Keychron K11 Max Nicola 配列キーマップ利用ガイド

このキーマップは、Keychron K11 Max (ANSI) で親指シフト（Nicola）入力を行うための特別仕様です。

## 主な機能と操作方法

### 1. 親指シフト（Nicola）の切り替え
スペースキーの両隣にあるキーを使用して、Nicolaレイヤーのオン/オフとIME（日本語入力）を連動させて切り替えます。

*   **右親指キー (KANA_FN1):**
    *   **タップ:** NicolaレイヤーをONにし、IME ON (`KC_LNG1`) を送信します。
    *   **ホールド:** `FN1` レイヤーに切り替わります。
*   **左親指キー (EISU_FN1):**
    *   **タップ:** Nicolaレイヤーを強制的にOFFにし、IME OFF (`KC_LNG2`) を送信します。
    *   **ホールド:** `FN1` レイヤーに切り替わります。

### 2. Nicolaレイヤー (`_NICOLA`)
NicolaレイヤーがONの状態では、`users/nicola` ライブラリによる親指シフト入力が有効になります。
*   センターにある `NG_SHFTL` (左親指シフト) と `NG_SHFTR` (右親指シフト) を使用して、日本語入力を効率的に行えます。

### 3. FN1 レイヤー（ナビゲーション・設定）
FN1レイヤー（親指ホールド中）では、ホームポジションを崩さずにカーソル操作やデバイス設定が可能です。

#### 【左手】ナビゲーション（ESDFカーソル）
*   **E / S / D / F:** カーソルキー（上 / 左 / 下 / 右）
*   **W / R:** Home / End

#### 【右手】ナビゲーション（JKLM周辺）
*   **J / K:** Insert / Home
*   **L / ;:** PageUp / BackSpace (1文字削除)
*   **M / , / .:** Delete / End / PageDown

#### デバイス設定・メディア・ショートカット
*   **X / C / V:** Bluetooth接続先切り替え (BT_HST 1 / 2 / 3)
*   **左B:** バッテリー残量確認 (`BAT_LVL`)
*   **N:** VS Code Markdown Preview (`KC_MDN_PRV`: Ctrl + Shift + V を送信)
*   **Esc:** US Emulation モードのON/OFF切り替え (`TG_JP`)
*   **A:** Alt + ` (IME切り替えショートカット等)
*   **H:** 音量UP (`KC_VOLU`)
*   **N:** 音量DOWN (`KC_VOLD`)

#### バックライト制御
*   **右上端キー:** バックライトON/OFF (`BL_TOGG`)
*   **カーソル左キー:** バックライトON/OFF (`BL_TOGG`)
*   **カーソル下キー:** 輝度ダウン (`BL_DOWN`)
*   **カーソル上キー:** 輝度アップ (`BL_UP`)
*   **カーソル右キー:** 発光パターン切り替え (`BL_STEP`)

### 4. US Emulation モード
日本語OS環境でANSI（US）配列キーボードを使用する際の記号入力を補助する機能です。
*   有効な場合、一部の記号キーがUS配列の刻印通りに入力されるように自動的にエミュレーションを行います。

### 5. 便利ショートカット
*   **ウィンドウ移動:** `KC_WIN_SHFT_LEFT` (Win + Shift + Left)
    *   ベースレイヤーの右上端（Muteキーの下）に配置。
*   **Teamsミュート:** `KC_TEAM_MUTE` (Win + Alt + K)
    *   ベースレイヤーの最下段、右Cmdの左隣に配置。

## ビルド方法
以下のコマンドでビルドが可能です。
```bash
make keychron/k11_max/ansi_encoder/white:nicola
```
