# -*- coding: utf-8 -*-
# module de test de l'api rest (main)
# doc sur les tests:
#   https://fastapi.tiangolo.com/tutorial/testing/
#   https://fastapi.tiangolo.com/advanced/testing-dependencies/
# play tests in command line:
#    pytest

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
    movieResponse = response.json()
    assert response.status_code == 200
    assert (movieResponse['title'], movieResponse['year']) == (movieJson['title'], movieJson['year'])
    assert movieResponse['duration'] is None
    assert 'id' in movieResponse
    assert type(movieResponse['id']) == int



