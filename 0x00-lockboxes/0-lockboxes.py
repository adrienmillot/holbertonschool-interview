#!/usr/bin/python3
"""
    Determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    """
        Returns True if all the boxes can be opened, False otherwise
    """

    opened_boxes = [0]

    # Je récupère la prochaine boite dévérouillée
    for box in opened_boxes:
        # Pour chaque box, je parcours toutes les clés
        for key in boxes[box]:

            # Je n'ouvre pas la box déjà associé à la clé
            if key not in opened_boxes and key < len(boxes):

                # J'ouvre la boxe
                opened_boxes.append(key)

    return len(boxes) == len(opened_boxes)
