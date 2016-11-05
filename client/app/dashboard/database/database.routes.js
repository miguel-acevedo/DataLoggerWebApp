'use strict';

export default function routes($stateProvider) {
  'ngInject';

<<<<<<< HEAD
  $stateProvider.state('dashboard.database', {
=======
  $stateProvider.state('dashboard.car', {
>>>>>>> new page on front end
    url: '/database',
    parent: 'dashboard',
    template: '<database></database>'
  });
}
