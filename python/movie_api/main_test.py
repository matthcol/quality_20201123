# -*- coding: utf-8 -*-
# module de test de l'api rest (main)
from fastapi.testclient import TestClient

from main import app

client = TestClient(app)


def test_create_movie():
    # given: movie to add
    movieJson = {"title": "Joker", "year": 2019}
    # when
    response = client.post(
        "/movies/",
        headers={"X-Token": "coneofsilence"},
        json=movieJson,
    )
    # then
    assert response.status_code == 200
    assert response.json() == movieJson



