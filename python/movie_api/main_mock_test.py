# -*- coding: utf-8 -*-

# -*- coding: utf-8 -*-
# module de test de l'api rest (main)
# doc sur les tests:
#   https://fastapi.tiangolo.com/tutorial/testing/
#   https://fastapi.tiangolo.com/advanced/testing-dependencies/
#   https://testdriven.io/blog/fastapi-crud/
# play tests in command line:
#    pytest

import pytest
import json
from fastapi.testclient import TestClient

from main import app
import crud
from schemas import Movie

client = TestClient(app)


@pytest.fixture(scope="module")
def test_app():
    client = TestClient(app)
    yield client  # testing happens here

# mock crud

def test_create_movie(test_app, monkeypatch):
    test_request_payload = {"title": "Joker", "year": 2019}
    test_response_payload = {"id": 1, "title": "Joker", "year": 2019, "duration": None}
   

    # profil function correspond à la méthode à mocker
    # eventuellement en async si la methde mockée est async
    def mock_post(db, movie):
        test_movie_response = Movie(id=1, title="Joker",year=2019)
        return test_movie_response

    # bypass la fonction à simuler
    monkeypatch.setattr(crud, "create_movie", mock_post)

    response = test_app.post("/movies/", data=json.dumps(test_request_payload),)

    assert response.status_code == 200
    assert response.json() == test_response_payload




