# OpenStreetMap

## Inhalte

- [Über das OpenStreetMap Projekt](#ueber)
- [Lizenz](#lizenz)
- [Installation](#installation)
    - [Linux](#installationlinux)
        - [Benötigte Abhängigkeiten]()
        - [Programmargumente]()
    - [Windows](#installationwindoof)
- [Dokumentation](#dokumentation)

<a name="ueber"></a>
## Über das OpenStreetMap Projekt

Unser Programm erstellt einen Graphen aus einem Kartenausschnitt von OpenStreetMap. Hierbei werden alle Straßen mit einbezogen. Der Graph wird als Datei im *.gdi Format im Projektordner gespeichert. Ihr werdet nach dem starten des Programmes durch das Programm geführt (Konsolenausgabe). Um einen selbst gewählten Kartenausschnitt zu verwenden, muss dieser über die Export Funktion von OpenStreetMap exportiert, und der Downloadlink in unser Programm eingefügt werden.

<a name="lizenz"></a>

## Lizenz

Dieses Projekt steht unter der MIT-Lizenz. Für weitere Informationen siehe [LICENCE](https://github.com/lfleper/OpenStreetMap/blob/master/LICENCE).

<a name="installation"></a>

## Installation

<a name="installationlinux"></a>

### Linux

Damit das OpenStreeMap Projekt auf einem Linux System installiert werde kann, müssen zunächst einige Entwicklungsbibliotheken installiert werden.

Zuerst wird die [OpenSSL Library](https://packages.debian.org/de/jessie/libssl-dev) benötigt, die die Implementierung der Kryptographieprotokolle SSL und TLS enthählt:

```bash
sudo apt install libssl-dev
```

Außerdem wird die [libcurl Library ](https://curl.se/libcurl/) benötigt, die dafür sorgt, dass die Requests auf die OpenStreetMap API getätigt werden können.

```bash
sudo apt-get install libcurl4-openssl-dev
```

<a name="installationwindoof"></a>

### Linux CLion

Zunächst muss das Repository geclont werden.

```bash
git clone https://github.com/lfleper/OpenStreetMap.git
```

Wichtig: Bei dem kompilieren des Projekts darf nicht das Programmargument

```bash
-libcurl
```

vergessen werden.

In [CLion](https://www.jetbrains.com/de-de/clion/) können diese unter ["Run | Edit Configurations"](https://www.jetbrains.com/help/clion/run-debug-configuration.html) angepasst werden.

Anschließend kann das Projekt über "Run|Run openstreetmap" gestartet werden.

### Linux Terminal

Wenn Sie keine IDE zur verfügung haben können sie das Projekt ebenfalls mit CMake kompilieren.

Zunächst muss das Repository geclont werden.

```bash
git clone https://github.com/lfleper/OpenStreetMap.git
```

Anschließend wechseln Sie in Ihrer Linux Bash in das jeweilige Verzeichnis.

Nun führen sie folgende CMake Befehle aus und das Projekt wird kompiliert.

```bash
cmake -Bbuild -H.
cmake --build build --target all
```

Nun hat sich ein [build] Ordner erstellt, indem Sie die [openstreetmap] Datei finden, die sie wie folgt ausführen können.

```bash
./openstreetmap
```

### Windows

<a name="dokumentation"></a>

## Dokumentation

### Hinweise zu den OpenStreetMap Kartenausschnitten

Bei der Auswahl von Kartenausschnitten gib es zwei begrenzende Faktoren:

1. Einmal die von Openstreetmap vorgegebene Maximale Knotenanzahl (Diese darf nicht 50000 Knoten überschreiten).

2. Die andere Limitierung ist das Programm selbst und die Art wie bei OpenStreetMap Knoten definiert werden. Unser Programm bezieht sich nur auf die Knoten und Kanten von Straßen, Autobahnen oder Fußwegen und filtert andere Knoten heraus. Eine Kreuzung mit 4 Straßen hat nicht nur einen Knoten und vier Kanten, sondern mindestens 8 Knoten (Zwei für jede Straße). OSM Dateien beinhalten ebenfalls eine große Anzahl an Knoten zu Gebäuden, Grenzen, öffentlichen Einrichtungen und Läden. Dadurch das beim Einlesen der OSM Daten viele Knoten ausgefiltert werden ist die maximale Knotengröße von Kartenausschnitten sehr begrenzt.

Somit können größere Karten ausschnitte von ländlichen Gegenden gelesen werden, während kleinere Ausschnitte von Großstädten schnell zu groß werden und für eine zu hohe Bearbeitungslast sorgen.
Unser Tipp bei der Auswahl der Ausschnitte ist also: zunächst mit kleinen Ausschnitten zu testen, um sich später zu Größeren vorzuarbeiten.

### OpenStreetMap Kartenauschnitte Links generieren

Die einzulesenden Kartenausschnitte kann man sich wie folgt herunterladen:

1. [Openstreetmap.org](https://openstreetmap.org)
2. Auswahl des "Export" Buttons in der Oberen Menü-Leiste
3. Ort auf der Karte wählen und auf "Einen anderen Bereich manuell auswählen" klicken
4. Das Fenster ausbreiten oder verkleinern um den gewünschten Kartenausschnitt zu markieren
5. Den Export Button klicken -> Download wird gestartet
6. Download-Link kopieren (Im Browser mit einem Rechtsklick auf die heruntergeladene "map.osm" Datei und auf Downloadlink kopieren gehen.
7. Diesen Link dann in die Konsole des laufenden Programms einfügen.
