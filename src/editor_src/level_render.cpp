#include "level_render.h"

LevelRenderer::LevelRenderer(QStandardItemModel *tiles, QWidget *parent)
    : QWidget(parent), currentBlockSize(50), placingTiles(false)
{
    setFixedSize(2000, 2000);  
    scrollOffset = QPoint(0, 0);  
    backgroundText = "../src/mapas/tiles/background/beach_fondo.png";
}

void LevelRenderer::setTilePixmap(const QPixmap &pixmap, int blockSize, QString blockType, QString blockText)
{
    if (blockType == "fondo"){
        m_backgroundPixmap = pixmap;
        backgroundText = blockText;
    } else {
        m_tilePixmap = pixmap;
        currentBlockSize = blockSize; 
        currentBlockType = blockType;
    }
    currentBlockText = blockText;
    update();
}

void LevelRenderer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if (!m_backgroundPixmap.isNull())
    {
        painter.drawPixmap(0, 0, width(), height(), m_backgroundPixmap);
    }

    QRect visibleRect(scrollOffset, QSize(width(), height()));

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine));
    for (int x = scrollOffset.x() % currentBlockSize; x < width(); x += currentBlockSize)
    {
        painter.drawLine(x, 0, x, height());
    }
    for (int y = scrollOffset.y() % currentBlockSize; y < height(); y += currentBlockSize)
    {
        painter.drawLine(0, y, width(), y);
    }

    for (auto it = tileMap.begin(); it != tileMap.end(); ++it)
    {
        BlockCoordinates coords = it.key();
        QList<Tile> tiles = it.value();

        for (const Tile &tile : tiles)
        {
            QRect rect(coords.x * tile.blockSize - scrollOffset.x(),
                       coords.y * tile.blockSize - scrollOffset.y(),
                       tile.blockSize, tile.blockSize);

            if (rect.intersects(visibleRect))
            {
                painter.drawRect(rect);
                painter.drawPixmap(rect, tile.pixmap);
            }
        }
    }
}

void LevelRenderer::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !m_tilePixmap.isNull())
    {
        placeTile(event->pos());
        placingTiles = true;
    }
    else if (event->button() == Qt::RightButton)
    {
        removeTile(event->pos());
        placingTiles = true;
    }
}

void LevelRenderer::mouseMoveEvent(QMouseEvent *event)
{
    if (placingTiles && event->buttons() & Qt::LeftButton && !m_tilePixmap.isNull())
    {
        placeTile(event->pos());
    }
    else if (placingTiles && event->buttons() & Qt::RightButton)
    {
        removeTile(event->pos());
    }
}

void LevelRenderer::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton)
    {
        placingTiles = false;
    }
}


void LevelRenderer::placeTile(const QPoint &position)
{
    int x = (position.x() + scrollOffset.x()) / currentBlockSize;
    int y = (position.y() + scrollOffset.y()) / currentBlockSize;
    BlockCoordinates coords = { x, y };

    if (!tileMap.contains(coords))
    {
        QList<Tile> newList;
        tileMap.insert(coords, newList);
    }

    bool yaExiste = false;
    for (const Tile &tile : tileMap[coords])
    {
        if (tile.blockSize == currentBlockSize)
        {
            yaExiste = true;
            break;
        }
    }

    if (!yaExiste)
    {
        Tile nuevoTile = { m_tilePixmap, currentBlockSize,currentBlockType, currentBlockText};
        tileMap[coords].append(nuevoTile);
        update();
    }
}

void LevelRenderer::removeTile(const QPoint &position)
{
    int x = (position.x() + scrollOffset.x()) / currentBlockSize;
    int y = (position.y() + scrollOffset.y()) / currentBlockSize;
    BlockCoordinates coords = { x, y };

    if (tileMap.contains(coords))
    {
        for (int i = tileMap[coords].size() - 1; i >= 0; --i)
        {
            if (tileMap[coords][i].blockSize == currentBlockSize)
            {
                tileMap[coords].removeAt(i);
                break;
            }
        }

        if (tileMap[coords].isEmpty())
        {
            tileMap.remove(coords);
        }

        update();
    }
}

void LevelRenderer::limpiarMapa()
{
    tileMap.clear(); 
    update();  
}

void LevelRenderer::saveToFile(const QString &fileName) const
{
    YAML::Emitter emitter;
    emitter << YAML::BeginMap;

    // Sección para bloques 'solid'
    emitter << YAML::Key << "solid" << YAML::Value << YAML::BeginSeq;
    for (auto it = tileMap.begin(); it != tileMap.end(); ++it)
    {
        BlockCoordinates coords = it.key();
        QList<Tile> tiles = it.value(); 

        for (const Tile &tile : tiles)
        {
            if (tile.type == "solid")
            {
                emitter << YAML::BeginMap;
                emitter << YAML::Key << "x" << YAML::Value << coords.x*50;
                emitter << YAML::Key << "y" << YAML::Value << coords.y*50;
                emitter << YAML::Key << "width" << YAML::Value << 50;
                emitter << YAML::Key << "height" << YAML::Value << 50;
                emitter << YAML::Key << "imagen" << YAML::Value << tile.text.toStdString();
                emitter << YAML::EndMap;
            }
        }
    }
    emitter << YAML::EndSeq;


    emitter << YAML::Key << "triangulo_izquierdo" << YAML::Value << YAML::BeginSeq;
    for (auto it = tileMap.begin(); it != tileMap.end(); ++it)
    {
        BlockCoordinates coords = it.key();
        QList<Tile> tiles = it.value(); 

        for (const Tile &tile : tiles)
        {
            if (tile.type == "triangulo_izquierdo")
            {
                emitter << YAML::BeginMap;
                emitter << YAML::Key << "x" << YAML::Value << coords.x*50;
                emitter << YAML::Key << "y" << YAML::Value << coords.y*50;
                emitter << YAML::Key << "width" << YAML::Value << 50;
                emitter << YAML::Key << "height" << YAML::Value << 50;
                emitter << YAML::Key << "imagen" << YAML::Value << tile.text.toStdString();
                emitter << YAML::EndMap;
            }
        }
    }
    emitter << YAML::EndSeq;

    emitter << YAML::Key << "triangulo_derecho" << YAML::Value << YAML::BeginSeq;
    for (auto it = tileMap.begin(); it != tileMap.end(); ++it)
    {
        BlockCoordinates coords = it.key();
        QList<Tile> tiles = it.value(); 

        for (const Tile &tile : tiles)
        {
            if (tile.type == "triangulo_derecho")
            {
                emitter << YAML::BeginMap;
                emitter << YAML::Key << "x" << YAML::Value << coords.x*50;
                emitter << YAML::Key << "y" << YAML::Value << coords.y*50;
                emitter << YAML::Key << "width" << YAML::Value << 50;
                emitter << YAML::Key << "height" << YAML::Value << 50;
                emitter << YAML::Key << "imagen" << YAML::Value << tile.text.toStdString();
                emitter << YAML::EndMap;
            }
        }
    }
    emitter << YAML::EndSeq;

    emitter << YAML::Key << "zanahoria" << YAML::Value << YAML::BeginSeq;
    for (auto it = tileMap.begin(); it != tileMap.end(); ++it)
    {
        BlockCoordinates coords = it.key();
        QList<Tile> tiles = it.value();

        for (const Tile &tile : tiles)
        {
            if (tile.type == "zanahoria")
            {
                emitter << YAML::BeginMap;
                emitter << YAML::Key << "x" << YAML::Value << coords.x*25;
                emitter << YAML::Key << "y" << YAML::Value << coords.y*25;
                emitter << YAML::EndMap;
            }
        }
    }
    emitter << YAML::EndSeq;

    emitter << YAML::Key << "gema" << YAML::Value << YAML::BeginSeq;
    for (auto it = tileMap.begin(); it != tileMap.end(); ++it)
    {
        BlockCoordinates coords = it.key();
        QList<Tile> tiles = it.value(); 

        for (const Tile &tile : tiles)
        {
            if (tile.type == "gema")
            {
                emitter << YAML::BeginMap;
                emitter << YAML::Key << "x" << YAML::Value << coords.x*25;
                emitter << YAML::Key << "y" << YAML::Value << coords.y*25;
                emitter << YAML::EndMap;
            }
        }
    }
    emitter << YAML::EndSeq;

    emitter << YAML::Key << "moneda" << YAML::Value << YAML::BeginSeq;
    for (auto it = tileMap.begin(); it != tileMap.end(); ++it)
    {
        BlockCoordinates coords = it.key();
        QList<Tile> tiles = it.value(); 

        for (const Tile &tile : tiles)
        {
            if (tile.type == "moneda")
            {
                emitter << YAML::BeginMap;
                emitter << YAML::Key << "x" << YAML::Value << coords.x*25;
                emitter << YAML::Key << "y" << YAML::Value << coords.y*25;
                emitter << YAML::EndMap;
            }
        }
    }
    emitter << YAML::EndSeq;

    emitter << YAML::Key << "bala_veloz" << YAML::Value << YAML::BeginSeq;
    for (auto it = tileMap.begin(); it != tileMap.end(); ++it)
    {
        BlockCoordinates coords = it.key();
        QList<Tile> tiles = it.value(); 

        for (const Tile &tile : tiles)
        {
            if (tile.type == "bala_veloz")
            {
                emitter << YAML::BeginMap;
                emitter << YAML::Key << "x" << YAML::Value << coords.x*25;
                emitter << YAML::Key << "y" << YAML::Value << coords.y*25;
                emitter << YAML::EndMap;
            }
        }
    }
    emitter << YAML::EndSeq;

    emitter << YAML::Key << "cohete_rapido" << YAML::Value << YAML::BeginSeq;
    for (auto it = tileMap.begin(); it != tileMap.end(); ++it)
    {
        BlockCoordinates coords = it.key();
        QList<Tile> tiles = it.value(); 

        for (const Tile &tile : tiles)
        {
            if (tile.type == "cohete_rapido")
            {
                emitter << YAML::BeginMap;
                emitter << YAML::Key << "x" << YAML::Value << coords.x*25;
                emitter << YAML::Key << "y" << YAML::Value << coords.y*25;
                emitter << YAML::EndMap;
            }
        }
    }
    emitter << YAML::EndSeq;

    emitter << YAML::Key << "bruja" << YAML::Value << YAML::BeginSeq;
    for (auto it = tileMap.begin(); it != tileMap.end(); ++it)
    {
        BlockCoordinates coords = it.key();
        QList<Tile> tiles = it.value(); 

        for (const Tile &tile : tiles)
        {
            if (tile.type == "bruja")
            {
                emitter << YAML::BeginMap;
                emitter << YAML::Key << "x" << YAML::Value << coords.x*50;
                emitter << YAML::Key << "y" << YAML::Value << coords.y*50;
                emitter << YAML::EndMap;
            }
        }
    }
    emitter << YAML::EndSeq;

    emitter << YAML::Key << "lizzard" << YAML::Value << YAML::BeginSeq;
    for (auto it = tileMap.begin(); it != tileMap.end(); ++it)
    {
        BlockCoordinates coords = it.key();
        QList<Tile> tiles = it.value(); 

        for (const Tile &tile : tiles)
        {
            if (tile.type == "lizzard")
            {
                emitter << YAML::BeginMap;
                emitter << YAML::Key << "x" << YAML::Value << coords.x*50;
                emitter << YAML::Key << "y" << YAML::Value << coords.y*50;
                emitter << YAML::EndMap;
            }
        }
    }
    emitter << YAML::EndSeq;

    emitter << YAML::Key << "fencer" << YAML::Value << YAML::BeginSeq;
    for (auto it = tileMap.begin(); it != tileMap.end(); ++it)
    {
        BlockCoordinates coords = it.key();
        QList<Tile> tiles = it.value(); 

        for (const Tile &tile : tiles)
        {
            if (tile.type == "fencer")
            {
                emitter << YAML::BeginMap;
                emitter << YAML::Key << "x" << YAML::Value << coords.x*50;
                emitter << YAML::Key << "y" << YAML::Value << coords.y*50;
                emitter << YAML::EndMap;
            }
        }
    }
    emitter << YAML::EndSeq;

    emitter << YAML::Key << "rat" << YAML::Value << YAML::BeginSeq;
    for (auto it = tileMap.begin(); it != tileMap.end(); ++it)
    {
        BlockCoordinates coords = it.key();
        QList<Tile> tiles = it.value(); 

        for (const Tile &tile : tiles)
        {
            if (tile.type == "rat")
            {
                emitter << YAML::BeginMap;
                emitter << YAML::Key << "x" << YAML::Value << coords.x*50;
                emitter << YAML::Key << "y" << YAML::Value << coords.y*50+20;
                emitter << YAML::EndMap;
            }
        }
    }
    emitter << YAML::EndSeq;

    emitter << YAML::Key << "fondo" << YAML::Value << backgroundText.toStdString();

    emitter << YAML::EndMap;

    std::ofstream fout(fileName.toStdString());
    fout << emitter.c_str();  
}

void LevelRenderer::loadFromFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream stream(&file);
    QString yamlContent = stream.readAll();
    file.close();

    YAML::Node node = YAML::Load(yamlContent.toStdString());
    tileMap.clear();

    for (const auto &tileNode : node["tiles"])
    {
        int x = tileNode["x"].as<int>();
        int y = tileNode["y"].as<int>();
        int blockSize = tileNode["blockSize"].as<int>();
        QString pixmapData = QString::fromStdString(tileNode["pixmap"].as<std::string>());

        QPixmap pixmap;
        pixmap.loadFromData(QByteArray::fromBase64(pixmapData.toUtf8()), "PNG");

        BlockCoordinates coords = { x, y };
        Tile tile = { pixmap, blockSize };

        tileMap[coords].append(tile);
    }

    update();
}
