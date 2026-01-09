#ifndef NOTEMODEL_H
#define NOTEMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QList>

#include "Note.h"

class NoteModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit NoteModel(QObject *parent = nullptr);

    enum NoteRoles {
        TitleRole = Qt::UserRole + 1,
        ContentRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    // Return the data for a specific index and role
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Map Enum to string names for QML ("title", "content")
    QHash<int, QByteArray> roleNames() const override;

    // Functions marked with Q_INVOKABLE can be called from .qml files
    Q_INVOKABLE void addNote(const QString &title, const QString &content);
    Q_INVOKABLE void removeNote(int index);

private:
    // The internal data container
    QList<Note> m_notes;
};

#endif // NOTEMODEL_H