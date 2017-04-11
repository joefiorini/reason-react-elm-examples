const path = require('path');

module.exports = {
  entry: {
    'unordered-list': './lib/js/src/unordered-list/root.js',
    buttons: './lib/js/src/buttons/buttonsRoot.js',
    field: './lib/js/src/field/fieldRoot.js',
  },
  output: {
    path: path.join(__dirname, 'bundledOutputs'),
    filename: '[name].js',
  },
};
