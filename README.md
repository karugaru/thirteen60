# Thirteen60

Thirteen60は5x6と5x7の非分割、左右非対称の自作キーボードキットです。
Poker/GH60/Tohu60互換ケースに準対応(一部加工が必要)で、接続方法は有線接続のみです。

## 回路図

回路図は`circuit/`ディレクトリに配置しています。

## ビルドガイド

キットのビルドガイドは`build_guide/`ディレクトリに配置しています。

頒布した版によってビルドガイドの内容が異なる場合がありますので、ビルドガイドの内容をよく確認してください。

## ファームウェア

ファームウェアは[QMK Firmware](https://github.com/qmk/qmk_firmware)を使用しています。

ボード固有の設定などのソースコードは`firmware/karugaru`ディレクトリに配置しています。
ビルド済みのファームウェアは`firmware/prebuilt`ディレクトリに配置しています。

本来はqmk_firmwareにプルリクエストをする予定でしたが、マージの手間などを考慮して独立したリポジトリとして管理しています。
利用する場合はご自身でQMK Firmwareをクローン/フォークした後に、`qmk_firmware/keyboards`に`firmware/karugaru`をコピーして使用してください。
